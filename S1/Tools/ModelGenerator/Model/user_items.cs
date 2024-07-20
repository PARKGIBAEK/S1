using System;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;
using Microsoft.EntityFrameworkCore;

namespace API.Model;

[Keyless]
public class user_items
{
    public int profile_id { get; set; }
    public int item_id { get; set; }
    public int? item_quantity { get; set; }
    public int item_type { get; set; }
    [DatabaseGenerated(DatabaseGeneratedOption.Identity)]
    public TimeSpan? created_at { get; set; }
    [DatabaseGenerated(DatabaseGeneratedOption.Computed)]
    public TimeSpan? updated_at { get; set; }
}