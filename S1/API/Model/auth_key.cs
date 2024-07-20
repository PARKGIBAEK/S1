using System;

namespace API.Model;

public class auth_key
{
    public int id { get; set; }
    public string key_value { get; set; }
    public DateTime created_at { get; set; }
}