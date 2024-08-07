using API.Helper;
using Microsoft.AspNetCore.Mvc.Controllers;

public class ControllerLoggingStartupFilter : IStartupFilter
{
    public Action<IApplicationBuilder> Configure(Action<IApplicationBuilder> next)
    {
        return app =>
        {
            app.Use(async (context, nextMiddleware) =>
            {
                var endpoint = context.GetEndpoint();
                if (endpoint != null)
                {
                    var controllerActionDescriptor = endpoint.Metadata.GetMetadata<ControllerActionDescriptor>();
                    if (controllerActionDescriptor != null)
                    {
                        ConsoleHelper.PrintSuccessMessage($"Constructor called for: {controllerActionDescriptor.ControllerName}");
                    }
                }
                await nextMiddleware();
            });

            next(app);
        };
    }
}
