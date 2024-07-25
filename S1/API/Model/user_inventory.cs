using System;

namespace API.Model;

public class user_inventory
{
    public int id { get; set; }
    public int user_character_id { get; set; }
    public int item_id { get; set; }
    public int item_quantity { get; set; }
    public DateTime created_at { get; set; }
    public DateTime updated_at { get; set; }
}