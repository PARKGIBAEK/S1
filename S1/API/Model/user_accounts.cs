using System;

namespace API.Model;

public class user_accounts
{
    public int id { get; set; }
    public string user_id { get; set; }
    public string user_name { get; set; }
    public string password { get; set; }
    public string email { get; set; }
    public DateTime created_at { get; set; }
    public DateTime updated_at { get; set; }
}