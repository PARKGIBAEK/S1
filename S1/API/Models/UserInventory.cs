using System;
using System.Collections.Generic;

namespace API.Models;

public partial class UserInventory
{
    public int Id { get; set; }

    public int CharacterId { get; set; }

    public int ItemId { get; set; }

    public int Quantity { get; set; }

    public DateTime CreatedAt { get; set; }

    public DateTime UpdatedAt { get; set; }
}
