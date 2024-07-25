using API.Data;
using API.Model;
using Microsoft.EntityFrameworkCore;

namespace API.Services;

public class ItemService(GameDbContext dbContext)
{
    private readonly GameDbContext _dbContext = dbContext;

    public async Task<user_inventory> AddItemAsync(int userCharacterId, int itemId, int quantity)
    {
        var userItem = new user_inventory
        {
            user_character_id = userCharacterId,
            item_id = itemId,
            item_quantity = quantity
        };

        dbContext.user_items.Add(userItem);
        await dbContext.SaveChangesAsync();
        return userItem;
    }

    public async Task<bool> ConsumeItemAsync(int userCharacterId, int itemId, int itemQuantity)
    {
        var userItem = await _dbContext.user_items.FirstOrDefaultAsync(item =>
            item.user_character_id == userCharacterId && item.item_id == itemId);
        if (userItem == null || userItem.item_quantity < itemQuantity)
        {
            return false;
        }

        userItem.item_quantity -= itemQuantity; // userItem은 참조타입이므로 dbContext의 user_items테이블 원본 값이 변경된다
        await dbContext.SaveChangesAsync();
        return true;
    }

    public async Task<bool> DeleteItemAsync(int userCharacterId, int itemId)
    {
        var userItem = await dbContext.user_items.FirstOrDefaultAsync(item =>
            item.user_character_id == userCharacterId && item.item_id == itemId);
        if (userItem == null)
            return false;
        _dbContext.user_items.Remove(userItem);
        await dbContext.SaveChangesAsync();
        return true;
    }
}