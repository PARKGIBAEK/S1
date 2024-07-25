namespace API.DTO;

public class ConsumeItemRequest
{
    public int UserCharacterId { get; set; }
    public int ItemId { get; set; }
    public int Quantity { get; set; }
}