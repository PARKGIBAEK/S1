using API.DTO;
using API.Services;
using Microsoft.AspNetCore.Mvc;

namespace API.Controllers;

[ApiController]
[Route("api/controller/item")]
public class ItemController(ItemService itemService) : ControllerBase
{
    private readonly ItemService _itemService = itemService;

    [HttpPost("add")]
    public async Task<IActionResult> AddItem([FromBody] AddItemRequest request)
    {
        var item = await _itemService.AddItemAsync(request.UserCharacterId, request.ItemId, request.Quantity);
        return Ok(item);
    }

    [HttpPost("consume")]
    public async Task<IActionResult> ConsumeItem([FromBody] ConsumeItemRequest request)
    {
        var success = await _itemService.ConsumeItemAsync(request.UserCharacterId, request.ItemId, request.Quantity);
        return Ok(success);
    }

    [HttpPost("delete")]
    public async Task<IActionResult> DeleteItem([FromBody] DeleteItemRequest request)
    {
        var success = await _itemService.DeleteItemAsync(request.UserCharacterId, request.ItemId);
        return Ok(success);
    }
    
}