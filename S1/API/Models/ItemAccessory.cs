using System;
using System.Collections.Generic;

namespace API.Models;

public partial class ItemAccessory
{
    public int Id { get; set; }

    public string ItemName { get; set; } = null!;

    public string? ItemDescription { get; set; }

    public int? ItemEffect { get; set; }
}
