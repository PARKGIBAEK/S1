using System;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;
using Microsoft.EntityFrameworkCore;

namespace API.Model;

public class auth_key
{
    [Key]
    [DatabaseGenerated(DatabaseGeneratedOption.Identity)]
    public int? id { get; set; }
    public string key_value { get; set; }
    [DatabaseGenerated(DatabaseGeneratedOption.Identity)]
    public DateTime? created_at { get; set; }
}