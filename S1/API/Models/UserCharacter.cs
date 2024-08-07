using System;
using System.Collections.Generic;

namespace API.Models;

public partial class UserCharacter
{
    public int Id { get; set; }

    public string UserId { get; set; } = null!;

    public string CharacterName { get; set; } = null!;

    public int? Level { get; set; }

    public long? Experience { get; set; }

    public long? Gold { get; set; }

    public DateTime CreatedAt { get; set; }

    public DateTime UpdatedAt { get; set; }

    public virtual UserAccount User { get; set; } = null!;
}
