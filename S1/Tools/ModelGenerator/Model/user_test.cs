using System;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;
using Microsoft.EntityFrameworkCore;

namespace API.Model;

public class user_test
{
    [Key]
    public int? user_id { get; set; }
    public string username { get; set; }
    public string password { get; set; }
    public string email { get; set; }
    [DatabaseGenerated(DatabaseGeneratedOption.Identity)]
    public TimeSpan? created_at { get; set; }
    [DatabaseGenerated(DatabaseGeneratedOption.Computed)]
    public TimeSpan? updated_at { get; set; }
}