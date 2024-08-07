using System;
using System.Collections.Generic;

namespace API.Models;

public partial class ItemArmor
{
    public int Id { get; set; }

    public string ItemName { get; set; } = null!;

    public string? ItemDescription { get; set; }

    public int DefensePower { get; set; }

    public int? ItemEffect { get; set; }
}
