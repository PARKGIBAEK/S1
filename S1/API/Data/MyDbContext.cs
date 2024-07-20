// MyDbContext.cs
using Microsoft.EntityFrameworkCore;
using API.Model;

namespace API.Data;


/* DB naming convention은 DB표준 스타일 가이드에 따라 snake_case를 준수할 것.
 * (DB와 관련된 것이라는 것을 명시하기 위함) */
/* 참고로 EF Core는 Primary Key가 없으면 없다고 명시해야 된다.
 (Model에 [Keyless] attribute를 사용하거나,
 DbContext의 OnModelCreating메서드에 HasNoKey를 명시하는 방식).
 따라서 웬만하면 테이블에 PK를 생성하도록하자.
 MySQL은 어차피 PK가 없으면 내부적으로 히든 Clustered-Index를 생성한다*/
public class MyDbContext(DbContextOptions<MyDbContext> options) : DbContext(options)
{

	// DB 테이블을 나타내는 DbSet 속성을 정의합니다.
	public DbSet<auth_key> auth_key { get; set; }
	public DbSet<user_accounts> user_accounts { get; set; }
	public DbSet<user_characters> user_characters { get; set; }
	public DbSet<user_items> user_items { get; set; }
	public DbSet<item_weapons> item_weapons { get; set; }
	public DbSet<item_armors> item_armors { get; set; }
	public DbSet<item_accessories> item_accessories { get; set; }
	public DbSet<user_test> user_test { get; set; }


}
