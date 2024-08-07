﻿// <auto-generated />
using System;
using API.Models;
using Microsoft.EntityFrameworkCore;
using Microsoft.EntityFrameworkCore.Infrastructure;
using Microsoft.EntityFrameworkCore.Metadata;
using Microsoft.EntityFrameworkCore.Storage.ValueConversion;

#nullable disable

namespace API.Migrations
{
    [DbContext(typeof(GameServerDbContext))]
    partial class GameServerDbContextModelSnapshot : ModelSnapshot
    {
        protected override void BuildModel(ModelBuilder modelBuilder)
        {
#pragma warning disable 612, 618
            modelBuilder
                .UseCollation("utf8mb4_general_ci")
                .HasAnnotation("ProductVersion", "8.0.7")
                .HasAnnotation("Relational:MaxIdentifierLength", 64);

            MySqlModelBuilderExtensions.HasCharSet(modelBuilder, "utf8mb4");
            MySqlModelBuilderExtensions.AutoIncrementColumns(modelBuilder);

            modelBuilder.Entity("API.Models.AuthKey", b =>
                {
                    b.Property<int>("Id")
                        .ValueGeneratedOnAdd()
                        .HasColumnType("int(11)")
                        .HasColumnName("id");

                    MySqlPropertyBuilderExtensions.UseMySqlIdentityColumn(b.Property<int>("Id"));

                    b.Property<DateTime>("CreatedAt")
                        .ValueGeneratedOnAdd()
                        .HasColumnType("timestamp")
                        .HasColumnName("created_at")
                        .HasDefaultValueSql("current_timestamp()");

                    b.Property<string>("KeyValue")
                        .IsRequired()
                        .HasMaxLength(256)
                        .HasColumnType("varchar(256)")
                        .HasColumnName("key_value");

                    b.HasKey("Id")
                        .HasName("PRIMARY");

                    b.HasIndex(new[] { "CreatedAt" }, "idx_created_at");

                    b.HasIndex(new[] { "KeyValue" }, "key_value")
                        .IsUnique();

                    b.ToTable("auth_key", (string)null);
                });

            modelBuilder.Entity("API.Models.ItemAccessory", b =>
                {
                    b.Property<int>("Id")
                        .HasColumnType("int(11)")
                        .HasColumnName("id");

                    b.Property<string>("ItemDescription")
                        .HasColumnType("text")
                        .HasColumnName("item_description");

                    b.Property<int?>("ItemEffect")
                        .HasColumnType("int(11)")
                        .HasColumnName("item_effect");

                    b.Property<string>("ItemName")
                        .IsRequired()
                        .HasMaxLength(64)
                        .HasColumnType("varchar(64)")
                        .HasColumnName("item_name");

                    b.HasKey("Id")
                        .HasName("PRIMARY");

                    b.ToTable("item_accessory", (string)null);
                });

            modelBuilder.Entity("API.Models.ItemArmor", b =>
                {
                    b.Property<int>("Id")
                        .HasColumnType("int(11)")
                        .HasColumnName("id");

                    b.Property<int>("DefensePower")
                        .HasColumnType("int(11)")
                        .HasColumnName("defense_power");

                    b.Property<string>("ItemDescription")
                        .HasColumnType("text")
                        .HasColumnName("item_description");

                    b.Property<int?>("ItemEffect")
                        .HasColumnType("int(11)")
                        .HasColumnName("item_effect");

                    b.Property<string>("ItemName")
                        .IsRequired()
                        .HasMaxLength(64)
                        .HasColumnType("varchar(64)")
                        .HasColumnName("item_name");

                    b.HasKey("Id")
                        .HasName("PRIMARY");

                    b.ToTable("item_armor", (string)null);
                });

            modelBuilder.Entity("API.Models.ItemWeapon", b =>
                {
                    b.Property<int>("Id")
                        .HasColumnType("int(11)")
                        .HasColumnName("id");

                    b.Property<int>("AttackPower")
                        .HasColumnType("int(11)")
                        .HasColumnName("attack_power");

                    b.Property<string>("ItemDescription")
                        .HasColumnType("text")
                        .HasColumnName("item_description");

                    b.Property<int?>("ItemEffect")
                        .HasColumnType("int(11)")
                        .HasColumnName("item_effect");

                    b.Property<string>("ItemName")
                        .IsRequired()
                        .HasMaxLength(64)
                        .HasColumnType("varchar(64)")
                        .HasColumnName("item_name");

                    b.HasKey("Id")
                        .HasName("PRIMARY");

                    b.ToTable("item_weapon", (string)null);
                });

            modelBuilder.Entity("API.Models.UserAccount", b =>
                {
                    b.Property<int>("Id")
                        .ValueGeneratedOnAdd()
                        .HasColumnType("int(11)")
                        .HasColumnName("id");

                    MySqlPropertyBuilderExtensions.UseMySqlIdentityColumn(b.Property<int>("Id"));

                    b.Property<DateTime>("CreatedAt")
                        .ValueGeneratedOnAdd()
                        .HasColumnType("timestamp")
                        .HasColumnName("created_at")
                        .HasDefaultValueSql("current_timestamp()");

                    b.Property<string>("Email")
                        .IsRequired()
                        .HasMaxLength(100)
                        .HasColumnType("varchar(100)")
                        .HasColumnName("email");

                    b.Property<string>("Password")
                        .IsRequired()
                        .HasMaxLength(64)
                        .HasColumnType("varchar(64)")
                        .HasColumnName("password");

                    b.Property<DateTime>("UpdatedAt")
                        .ValueGeneratedOnAddOrUpdate()
                        .HasColumnType("timestamp")
                        .HasColumnName("updated_at")
                        .HasDefaultValueSql("current_timestamp()");

                    MySqlPropertyBuilderExtensions.UseMySqlComputedColumn(b.Property<DateTime>("UpdatedAt"));

                    b.Property<string>("UserId")
                        .IsRequired()
                        .HasMaxLength(24)
                        .HasColumnType("varchar(24)")
                        .HasColumnName("user_id");

                    b.Property<string>("UserName")
                        .IsRequired()
                        .HasMaxLength(32)
                        .HasColumnType("varchar(32)")
                        .HasColumnName("user_name");

                    b.HasKey("Id")
                        .HasName("PRIMARY");

                    b.HasIndex(new[] { "Email" }, "email")
                        .IsUnique();

                    b.HasIndex(new[] { "CreatedAt" }, "idx_created_at")
                        .HasDatabaseName("idx_created_at1");

                    b.HasIndex(new[] { "UserId" }, "user_id")
                        .IsUnique();

                    b.ToTable("user_account", (string)null);
                });

            modelBuilder.Entity("API.Models.UserCharacter", b =>
                {
                    b.Property<int>("Id")
                        .ValueGeneratedOnAdd()
                        .HasColumnType("int(11)")
                        .HasColumnName("id");

                    MySqlPropertyBuilderExtensions.UseMySqlIdentityColumn(b.Property<int>("Id"));

                    b.Property<string>("CharacterName")
                        .IsRequired()
                        .HasMaxLength(32)
                        .HasColumnType("varchar(32)")
                        .HasColumnName("character_name");

                    b.Property<DateTime>("CreatedAt")
                        .ValueGeneratedOnAdd()
                        .HasColumnType("timestamp")
                        .HasColumnName("created_at")
                        .HasDefaultValueSql("current_timestamp()");

                    b.Property<long?>("Experience")
                        .ValueGeneratedOnAdd()
                        .HasColumnType("bigint(20)")
                        .HasColumnName("experience")
                        .HasDefaultValueSql("'0'");

                    b.Property<long?>("Gold")
                        .ValueGeneratedOnAdd()
                        .HasColumnType("bigint(20)")
                        .HasColumnName("gold")
                        .HasDefaultValueSql("'0'");

                    b.Property<int?>("Level")
                        .ValueGeneratedOnAdd()
                        .HasColumnType("int(11)")
                        .HasColumnName("level")
                        .HasDefaultValueSql("'1'");

                    b.Property<DateTime>("UpdatedAt")
                        .ValueGeneratedOnAddOrUpdate()
                        .HasColumnType("timestamp")
                        .HasColumnName("updated_at")
                        .HasDefaultValueSql("current_timestamp()");

                    MySqlPropertyBuilderExtensions.UseMySqlComputedColumn(b.Property<DateTime>("UpdatedAt"));

                    b.Property<string>("UserId")
                        .IsRequired()
                        .HasMaxLength(24)
                        .HasColumnType("varchar(24)")
                        .HasColumnName("user_id");

                    b.HasKey("Id")
                        .HasName("PRIMARY");

                    b.HasIndex(new[] { "CharacterName" }, "character_name")
                        .IsUnique();

                    b.HasIndex(new[] { "UserId" }, "index_user_id");

                    b.ToTable("user_character", (string)null);
                });

            modelBuilder.Entity("API.Models.UserInventory", b =>
                {
                    b.Property<int>("Id")
                        .ValueGeneratedOnAdd()
                        .HasColumnType("int(11)")
                        .HasColumnName("id");

                    MySqlPropertyBuilderExtensions.UseMySqlIdentityColumn(b.Property<int>("Id"));

                    b.Property<int>("CharacterId")
                        .HasColumnType("int(11)")
                        .HasColumnName("character_id");

                    b.Property<DateTime>("CreatedAt")
                        .ValueGeneratedOnAdd()
                        .HasColumnType("timestamp")
                        .HasColumnName("created_at")
                        .HasDefaultValueSql("current_timestamp()");

                    b.Property<int>("ItemId")
                        .HasColumnType("int(11)")
                        .HasColumnName("item_id");

                    b.Property<int>("Quantity")
                        .ValueGeneratedOnAdd()
                        .HasColumnType("int(11)")
                        .HasColumnName("quantity")
                        .HasDefaultValueSql("'1'");

                    b.Property<DateTime>("UpdatedAt")
                        .ValueGeneratedOnAddOrUpdate()
                        .HasColumnType("timestamp")
                        .HasColumnName("updated_at")
                        .HasDefaultValueSql("current_timestamp()");

                    MySqlPropertyBuilderExtensions.UseMySqlComputedColumn(b.Property<DateTime>("UpdatedAt"));

                    b.HasKey("Id")
                        .HasName("PRIMARY");

                    b.HasIndex(new[] { "CharacterId" }, "idx_character_id");

                    b.HasIndex(new[] { "ItemId", "CreatedAt" }, "idx_item_id_create_at");

                    b.ToTable("user_inventory", (string)null);
                });

            modelBuilder.Entity("API.Models.UserTest", b =>
                {
                    b.Property<int>("Id")
                        .ValueGeneratedOnAdd()
                        .HasColumnType("int(11)")
                        .HasColumnName("id");

                    MySqlPropertyBuilderExtensions.UseMySqlIdentityColumn(b.Property<int>("Id"));

                    b.Property<DateTime>("CreatedAt")
                        .ValueGeneratedOnAdd()
                        .HasColumnType("timestamp")
                        .HasColumnName("created_at")
                        .HasDefaultValueSql("current_timestamp()");

                    b.Property<string>("Email")
                        .IsRequired()
                        .HasMaxLength(64)
                        .HasColumnType("varchar(64)")
                        .HasColumnName("email");

                    b.Property<string>("Password")
                        .IsRequired()
                        .HasMaxLength(32)
                        .HasColumnType("varchar(32)")
                        .HasColumnName("password");

                    b.Property<DateTime>("UpdatedAt")
                        .ValueGeneratedOnAddOrUpdate()
                        .HasColumnType("timestamp")
                        .HasColumnName("updated_at")
                        .HasDefaultValueSql("current_timestamp()");

                    MySqlPropertyBuilderExtensions.UseMySqlComputedColumn(b.Property<DateTime>("UpdatedAt"));

                    b.Property<string>("Username")
                        .IsRequired()
                        .HasMaxLength(32)
                        .HasColumnType("varchar(32)")
                        .HasColumnName("username");

                    b.HasKey("Id")
                        .HasName("PRIMARY");

                    b.HasIndex(new[] { "Email" }, "email")
                        .IsUnique()
                        .HasDatabaseName("email1");

                    b.ToTable("user_test", (string)null);
                });

            modelBuilder.Entity("API.Models.UserCharacter", b =>
                {
                    b.HasOne("API.Models.UserAccount", "User")
                        .WithMany("UserCharacters")
                        .HasForeignKey("UserId")
                        .HasPrincipalKey("UserId")
                        .IsRequired()
                        .HasConstraintName("user_character_ibfk_1");

                    b.Navigation("User");
                });

            modelBuilder.Entity("API.Models.UserAccount", b =>
                {
                    b.Navigation("UserCharacters");
                });
#pragma warning restore 612, 618
        }
    }
}
