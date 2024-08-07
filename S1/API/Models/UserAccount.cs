using System;
using System.Collections.Generic;

namespace API.Models;

public partial class UserAccount
{
    public int Id { get; set; }

    public string UserId { get; set; } = null!;

    public string UserName { get; set; } = null!;

    public string Password { get; set; } = null!;

    public string Email { get; set; } = null!;

    public DateTime CreatedAt { get; set; }

    public DateTime UpdatedAt { get; set; }

    public virtual ICollection<UserCharacter> UserCharacters { get; set; } = new List<UserCharacter>();
}
