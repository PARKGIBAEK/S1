using System;

namespace API.Model;

public class user_test
{
    public int id { get; set; }
    public string username { get; set; }
    public string password { get; set; }
    public string email { get; set; }
    public DateTime created_at { get; set; }
    public DateTime updated_at { get; set; }
}