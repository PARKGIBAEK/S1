using System;
using System.Collections.Generic;

namespace API.Models;

public partial class AuthKey
{
    public int Id { get; set; }

    public string KeyValue { get; set; } = null!;

    public DateTime CreatedAt { get; set; }
}
