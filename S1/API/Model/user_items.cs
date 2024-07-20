using System;

namespace API.Model;

public class user_items
{
    public int id { get; set; }
    public int user_character_id { get; set; }
    public int item_id { get; set; }
    public int item_quantity { get; set; }
    public int item_type { get; set; }
    public DateTime created_at { get; set; }
    public DateTime updated_at { get; set; }
}