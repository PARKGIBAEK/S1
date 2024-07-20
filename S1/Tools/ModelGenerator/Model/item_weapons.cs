using System;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;
using Microsoft.EntityFrameworkCore;

namespace API.Model;

public class item_weapons
{
    [Key]
    public int? item_id { get; set; }
    public string item_name { get; set; }
    public string item_description { get; set; }
    public int? attack_power { get; set; }
    public int? item_effect { get; set; }
}