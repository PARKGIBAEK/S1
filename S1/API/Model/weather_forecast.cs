namespace API
{
	public class weather_forecast
	{
		public DateTime date { get; set; }

		public int temperature_c { get; set; }

		public int temperature_f => 32 + (int)(temperature_c / 0.5556);

		public string? summary { get; set; }
	}
}
