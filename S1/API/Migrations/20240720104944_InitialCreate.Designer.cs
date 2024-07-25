﻿// <auto-generated />
using System;
using API.Data;
using Microsoft.EntityFrameworkCore;
using Microsoft.EntityFrameworkCore.Infrastructure;
using Microsoft.EntityFrameworkCore.Metadata;
using Microsoft.EntityFrameworkCore.Migrations;
using Microsoft.EntityFrameworkCore.Storage.ValueConversion;

#nullable disable

namespace API.Migrations
{
    [DbContext(typeof(GameDbContext))]
    [Migration("20240720104944_InitialCreate")]
    partial class InitialCreate
    {
        /// <inheritdoc />
        protected override void BuildTargetModel(ModelBuilder modelBuilder)
        {
#pragma warning disable 612, 618
            modelBuilder
                .HasAnnotation("ProductVersion", "8.0.7")
                .HasAnnotation("Relational:MaxIdentifierLength", 64);

            MySqlModelBuilderExtensions.AutoIncrementColumns(modelBuilder);

            modelBuilder.Entity("API.Model.auth_key", b =>
                {
                    b.Property<int>("id")
                        .ValueGeneratedOnAdd()
                        .HasColumnType("int");

                    MySqlPropertyBuilderExtensions.UseMySqlIdentityColumn(b.Property<int>("id"));

                    b.Property<DateTime>("created_at")
                        .HasColumnType("datetime(6)");

                    b.Property<string>("key_value")
                        .IsRequired()
                        .HasColumnType("longtext");

                    b.HasKey("id");

                    b.ToTable("auth_key");
                });

            modelBuilder.Entity("API.Model.item_accessories", b =>
                {
                    b.Property<int>("id")
                        .ValueGeneratedOnAdd()
                        .HasColumnType("int");

                    MySqlPropertyBuilderExtensions.UseMySqlIdentityColumn(b.Property<int>("id"));

                    b.Property<string>("item_description")
                        .IsRequired()
                        .HasColumnType("longtext");

                    b.Property<int>("item_effect")
                        .HasColumnType("int");

                    b.Property<string>("item_name")
                        .IsRequired()
                        .HasColumnType("longtext");

                    b.HasKey("id");

                    b.ToTable("item_accessories");
                });

            modelBuilder.Entity("API.Model.item_armors", b =>
                {
                    b.Property<int>("id")
                        .ValueGeneratedOnAdd()
                        .HasColumnType("int");

                    MySqlPropertyBuilderExtensions.UseMySqlIdentityColumn(b.Property<int>("id"));

                    b.Property<int>("defense_power")
                        .HasColumnType("int");

                    b.Property<string>("item_description")
                        .IsRequired()
                        .HasColumnType("longtext");

                    b.Property<int>("item_effect")
                        .HasColumnType("int");

                    b.Property<string>("item_name")
                        .IsRequired()
                        .HasColumnType("longtext");

                    b.HasKey("id");

                    b.ToTable("item_armors");
                });

            modelBuilder.Entity("API.Model.item_weapons", b =>
                {
                    b.Property<int>("id")
                        .ValueGeneratedOnAdd()
                        .HasColumnType("int");

                    MySqlPropertyBuilderExtensions.UseMySqlIdentityColumn(b.Property<int>("id"));

                    b.Property<int>("attack_power")
                        .HasColumnType("int");

                    b.Property<string>("item_description")
                        .IsRequired()
                        .HasColumnType("longtext");

                    b.Property<int>("item_effect")
                        .HasColumnType("int");

                    b.Property<string>("item_name")
                        .IsRequired()
                        .HasColumnType("longtext");

                    b.HasKey("id");

                    b.ToTable("item_weapons");
                });

            modelBuilder.Entity("API.Model.user_accounts", b =>
                {
                    b.Property<int>("id")
                        .ValueGeneratedOnAdd()
                        .HasColumnType("int");

                    MySqlPropertyBuilderExtensions.UseMySqlIdentityColumn(b.Property<int>("id"));

                    b.Property<DateTime>("created_at")
                        .HasColumnType("datetime(6)");

                    b.Property<string>("email")
                        .IsRequired()
                        .HasColumnType("longtext");

                    b.Property<string>("password")
                        .IsRequired()
                        .HasColumnType("longtext");

                    b.Property<DateTime>("updated_at")
                        .HasColumnType("datetime(6)");

                    b.Property<string>("user_id")
                        .IsRequired()
                        .HasColumnType("longtext");

                    b.Property<string>("user_name")
                        .IsRequired()
                        .HasColumnType("longtext");

                    b.HasKey("id");

                    b.ToTable("user_accounts");
                });

            modelBuilder.Entity("API.Model.user_characters", b =>
                {
                    b.Property<int>("id")
                        .ValueGeneratedOnAdd()
                        .HasColumnType("int");

                    MySqlPropertyBuilderExtensions.UseMySqlIdentityColumn(b.Property<int>("id"));

                    b.Property<string>("character_name")
                        .IsRequired()
                        .HasColumnType("longtext");

                    b.Property<DateTime>("created_at")
                        .HasColumnType("datetime(6)");

                    b.Property<long>("experience")
                        .HasColumnType("bigint");

                    b.Property<long>("gold")
                        .HasColumnType("bigint");

                    b.Property<int>("level")
                        .HasColumnType("int");

                    b.Property<DateTime>("updated_at")
                        .HasColumnType("datetime(6)");

                    b.Property<int>("user_accounts_id")
                        .HasColumnType("int");

                    b.HasKey("id");

                    b.ToTable("user_characters");
                });

            modelBuilder.Entity("API.Model.user_items", b =>
                {
                    b.Property<int>("id")
                        .ValueGeneratedOnAdd()
                        .HasColumnType("int");

                    MySqlPropertyBuilderExtensions.UseMySqlIdentityColumn(b.Property<int>("id"));

                    b.Property<DateTime>("created_at")
                        .HasColumnType("datetime(6)");

                    b.Property<int>("item_id")
                        .HasColumnType("int");

                    b.Property<int>("item_quantity")
                        .HasColumnType("int");

                    b.Property<int>("item_type")
                        .HasColumnType("int");

                    b.Property<DateTime>("updated_at")
                        .HasColumnType("datetime(6)");

                    b.Property<int>("user_character_id")
                        .HasColumnType("int");

                    b.HasKey("id");

                    b.ToTable("user_items");
                });

            modelBuilder.Entity("API.Model.user_test", b =>
                {
                    b.Property<int>("id")
                        .ValueGeneratedOnAdd()
                        .HasColumnType("int");

                    MySqlPropertyBuilderExtensions.UseMySqlIdentityColumn(b.Property<int>("id"));

                    b.Property<DateTime>("created_at")
                        .HasColumnType("datetime(6)");

                    b.Property<string>("email")
                        .IsRequired()
                        .HasColumnType("longtext");

                    b.Property<string>("password")
                        .IsRequired()
                        .HasColumnType("longtext");

                    b.Property<DateTime>("updated_at")
                        .HasColumnType("datetime(6)");

                    b.Property<string>("username")
                        .IsRequired()
                        .HasColumnType("longtext");

                    b.HasKey("id");

                    b.ToTable("user_test");
                });
#pragma warning restore 612, 618
        }
    }
}
