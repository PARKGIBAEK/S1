using API.DTO;
using API.Helper;
using API.Models;
using API.Services;
using Microsoft.AspNetCore.Mvc;

namespace API.Controllers;

[ApiController]
[Route("api/controller/item")]
public class ItemController(ItemService itemService) : ControllerBase
{
    [HttpPost("add")]
    public async Task<IActionResult> AddItem([FromBody] AddItemRequest request)
    {
        var item = await itemService.AddItemAsync(request.UserCharacterId, request.ItemId, request.Quantity);
        return Ok(item);
    }

    [HttpPost("consume")]
    public async Task<IActionResult> ConsumeItem([FromBody] ConsumeItemRequest request)
    {
        var success = await itemService.ConsumeItemAsync(request.UserCharacterId, request.ItemId, request.Quantity);
        return Ok(success);
    }

    [HttpPost("delete")]
    public async Task<IActionResult> DeleteItem([FromBody] DeleteItemRequest request)
    {
        var success = await itemService.DeleteItemAsync(request.UserCharacterId, request.ItemId);
        return Ok(success);
    }

}
