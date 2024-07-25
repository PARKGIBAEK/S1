using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Mvc;
using System.Collections.Generic;
using System.Linq;
using API.Data;
using API.Model;

namespace API.Controllers;


[ApiController]
[Route("[controller]")]
public class SampleController : ControllerBase
{
    private readonly GameDbContext _context;

    public SampleController(GameDbContext context)
    {
        _context = context;
    }

    // [HttpGet]
    // public ActionResult<IEnumerable<MyEntity>> Get()
    // {
    //     return _context.MyEntities.ToList();
    // }
    //
    // [HttpPost]
    // public ActionResult<MyEntity> Post(MyEntity entity)
    // {
    //     _context.MyEntities.Add(entity);
    //     _context.SaveChanges();
    //     return CreatedAtAction(nameof(Get), new { id = entity.Id }, entity);
    // }
}