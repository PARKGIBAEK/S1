using System;

namespace API.Model;

public class item_weapon
{
    public int id { get; set; }
    public string item_name { get; set; }
    public string item_description { get; set; }
    public int attack_power { get; set; }
    public int item_effect { get; set; }
}