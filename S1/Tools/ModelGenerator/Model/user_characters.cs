using System;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;
using Microsoft.EntityFrameworkCore;

namespace API.Model;

public class user_characters
{
    [Key]
    [DatabaseGenerated(DatabaseGeneratedOption.Identity)]
    public int? profile_id { get; set; }
    public int user_id { get; set; }
    public string character_name { get; set; }
    public int? level { get; set; }
    public long? experience { get; set; }
    public long? gold { get; set; }
    [DatabaseGenerated(DatabaseGeneratedOption.Identity)]
    public TimeSpan? created_at { get; set; }
    [DatabaseGenerated(DatabaseGeneratedOption.Computed)]
    public TimeSpan? updated_at { get; set; }
}