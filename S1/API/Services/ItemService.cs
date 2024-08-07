using API.DB;
using API.Models;
using Microsoft.EntityFrameworkCore;

namespace API.Services;

public class ItemService(GameServerDbContext dbContext, RedisManager redis)
{

    public async Task<UserInventory> AddItemAsync(int userCharacterId, int itemId, int quantity)
    {
        var userItem = new UserInventory
        {
            CharacterId = userCharacterId,
            ItemId = itemId,
            Quantity = quantity
        };

        dbContext.UserInventories.Add(userItem);
        await dbContext.SaveChangesAsync();
        return userItem;
    }

    public async Task<bool> ConsumeItemAsync(int userCharacterId, int itemId, int itemQuantity)
    {
        var userItem = await dbContext.UserInventories.FirstOrDefaultAsync(item =>
            item.CharacterId == userCharacterId && item.ItemId == itemId);
        if (userItem == null || userItem.Quantity < itemQuantity)
        {
            return false;
        }

        userItem.Quantity -= itemQuantity; // userItem은 참조타입이므로 dbContext의 user_items테이블 원본 값이 변경된다
        await dbContext.SaveChangesAsync();
        return true;
    }

    public async Task<bool> DeleteItemAsync(int userCharacterId, int itemId)
    {
        var userItem = await dbContext.UserInventories.FirstOrDefaultAsync(item =>
            item.CharacterId == userCharacterId && item.ItemId == itemId);
        if (userItem == null)
            return false;
        dbContext.UserInventories.Remove(userItem);
        await dbContext.SaveChangesAsync();
        return true;
    }
}
