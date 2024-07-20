using System;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;

public class item_accesories
{
    [Key]
    public int? item_id { get; set; }
    public string item_name { get; set; }
    public string item_description { get; set; }
    public int? item_effect { get; set; }
}