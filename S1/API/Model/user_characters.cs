using System;

namespace API.Model;

public class user_characters
{
    public int id { get; set; }
    public int user_accounts_id { get; set; }
    public string character_name { get; set; }
    public int level { get; set; }
    public long experience { get; set; }
    public long gold { get; set; }
    public DateTime created_at { get; set; }
    public DateTime updated_at { get; set; }
}