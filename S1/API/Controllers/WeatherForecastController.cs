using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Mvc;
using Microsoft.Extensions.Logging;
using System;
using System.Collections.Generic;
using System.Linq;

namespace API.Controllers;

[Authorize]
[ApiController]
[Route("[controller]")]
public class WeatherForecastController : ControllerBase
{
    private static readonly string[] Summaries = new[]
    {
        "Freezing", "Bracing", "Chilly", "Cool", "Mild", "Warm", "Balmy", "Hot", "Sweltering", "Scorching"
    };

    private readonly ILogger<WeatherForecastController> _logger;

    public WeatherForecastController(ILogger<WeatherForecastController> logger)
    {
        _logger = logger;
        _logger.LogInformation(("WeatherForecastController constructed"));
    }

    [HttpGet]
    public IEnumerable<weather_forecast> Get()
    {
        var rng = new Random();
        return Enumerable.Range(1, 5).Select(index => new weather_forecast
            {
                date = DateTime.Now.AddDays(index),
                temperature_c = rng.Next(-20, 55),
                summary = Summaries[rng.Next(Summaries.Length)]
            })
            .ToArray();
    }
}