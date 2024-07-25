namespace API.DTO;

public class AddItemRequest
{
    public int UserCharacterId { get; set; }
    public int ItemId { get; set; }
    public int Quantity { get; set; }
}