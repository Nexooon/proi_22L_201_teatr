#include "catch.hpp"

#include "../comedy.h"
#include "../data.h" //problems with add_random_play_to_repertuar - wywolanie metody powoduje blad kompilacji
#include "../date.h"
#include "../drama.h"
#include "../hall.h"                  //done
#include "../invalid_day_exception.h" //done
#include "../play.h"
// #include "../reduced_ticket_children.h"
// #include "../reduced_ticket_student.h"
#include "../regular_ticket.h"
#include "../repertuar.h" //done
#include "../theatre.h"
#include "../tragedy.h"
#include "../usher.h"  //done
#include "../worker.h" //done

using namespace std;

TEST_CASE("data tests", "[data]")
{
    Hall hall;
    Play play;
    Comedy comedy("com", 11, 120, 5);
    Drama drama("title", 12, 100, "murder");
    Tragedy tragedy("tra", 55, 230, "Jack");

    vector<Hall> halls;
    vector<Play> plays;
    vector<Comedy> comedies;
    vector<Drama> dramas;
    vector<Tragedy> tragedies;

    halls.push_back(hall);
    plays.push_back(play);
    comedies.push_back(comedy);
    dramas.push_back(drama);
    tragedies.push_back(tragedy);

    Data data(halls, plays, comedies, dramas, tragedies);

    CHECK(data.halls_size() == 1);
    CHECK(data.plays_size() == 1);
    CHECK(data.comedies_size() == 1);
    CHECK(data.dramas_size() == 1);
    CHECK(data.tragedies_size() == 1);

    Repertuar rep(halls.at(0));
    CHECK(rep.plays_list.size() == 0);
    // data.add_random_play_to_repertuar(rep);
    // CHECK(rep.plays_list.size() == 1);
    // list<unique_ptr<Play>>::iterator i = rep.plays_list.begin();
    // CHECK((*i)->get_title() == play.get_title());
}

TEST_CASE("Hall tests", "[hall]")
{
    Hall hall;
    CHECK(hall.get_number() == 1);
    CHECK(hall.get_seats() == 50);
    CHECK(hall.get_taken_seats() == 0);
    Hall h2(2, 10, 2);
    CHECK(h2.get_number() == 2);
    CHECK(h2.get_seats() == 10);
    CHECK(h2.get_taken_seats() == 2);

    SECTION("setters")
    {
        hall.set_number(3);
        CHECK(hall.get_number() == 3);
        REQUIRE_THROWS(hall.set_number(0));
        hall.set_seats(100);
        CHECK(hall.get_seats() == 100);
        REQUIRE_THROWS(hall.set_seats(0));
        hall.set_taken_seats(55);
        CHECK(hall.get_taken_seats() == 55);
    }
}

TEST_CASE("Repertuar tests", "[repertuar]")
{
    Hall hall(1, 100, 0);
    Play play;
    Drama drama("title", 12, 100, "murder");
    Comedy comedy("com", 11, 120, 5);
    Tragedy tragedy("tra", 55, 230, "Jack");

    Repertuar rep(hall);

    CHECK(rep.plays_list.size() == 0);
    rep.add_play(play);
    CHECK(rep.plays_list.size() == 1);
    list<unique_ptr<Play>>::iterator i = rep.plays_list.begin();
    CHECK((*i)->get_title() == play.get_title());

    rep.add_comedy(comedy);
    CHECK(rep.plays_list.size() == 2);
    i++;
    CHECK((*i)->get_title() == comedy.get_title());

    rep.add_drama(drama);
    CHECK(rep.plays_list.size() == 3);
    i++;
    CHECK((*i)->get_title() == drama.get_title());

    rep.add_tragedy(tragedy);
    CHECK(rep.plays_list.size() == 4);
    i++;
    CHECK((*i)->get_title() == tragedy.get_title());
}

TEST_CASE("worker tests", "[worker]")
{
    Worker worker("worker", "cleaning");
    CHECK(worker.get_name() == "worker");
    CHECK(worker.get_obligation() == "cleaning");
    CHECK(worker.get_day_hours("Monday") == "8:00 - 16:00");

    SECTION("setters")
    {
        worker.set_name("actor");
        CHECK(worker.get_name() == "actor");
        worker.set_obligation("aaa");
        CHECK(worker.get_obligation() == "aaa");
        worker.modify_schedule("Monday", "10:00 - 12:00");
        CHECK(worker.get_day_hours("Monday") == "10:00 - 12:00");
        REQUIRE_THROWS_AS(worker.modify_schedule("Sunday", "12:00 - 14:00"), InvalidDayException);
    }
}

TEST_CASE("usher tests", "[usher]")
{
    Usher usher("usher", "selling", 3);
    CHECK(usher.get_name() == "usher");
    CHECK(usher.get_obligation() == "selling");
    CHECK(usher.get_day_hours("Monday") == "9:00 - 15:00");
    CHECK(usher.get_sold_tickets() == 3);

    SECTION("setters")
    {
        usher.set_name("ush");
        CHECK(usher.get_name() == "ush");
        usher.set_obligation("aaa");
        CHECK(usher.get_obligation() == "aaa");
        usher.set_sold_tickets(6);
        CHECK(usher.get_sold_tickets() == 6);
        usher.modify_schedule("Monday", "10:00 - 12:00");
        CHECK(usher.get_day_hours("Monday") == "10:00 - 12:00");
        REQUIRE_THROWS_AS(usher.modify_schedule("Sunday", "12:00 - 14:00"), InvalidDayException);
    }
}

TEST_CASE("play simple tests")
{
    Play play("Dasa", 90, 3);

    CHECK(play.get_title() == "Dasa");
    CHECK(play.get_price() == 90);
    CHECK(play.get_duration() == 3);

    SECTION("test setters")
    {
        play.set_title("Mala");
        play.set_price(100);
        play.set_duration(4);

        CHECK(play.get_title() == "Mala");
        CHECK(play.get_price() == 100);
        CHECK(play.get_duration() == 4);
    }
}

TEST_CASE("comedy simple tests")
{
    Comedy comedy("Manga", 100, 10, 5);

    CHECK(comedy.get_title() == "Manga");
    CHECK(comedy.get_price() == 100);
    CHECK(comedy.get_duration() == 10);
    CHECK(comedy.get_nfunny_scenes() == 5);

    SECTION("test setters")
    {
        comedy.set_price(200);
        CHECK(comedy.get_title() == "Manga");
        CHECK(comedy.get_price() == 200);
        CHECK(comedy.get_duration() == 10);
        CHECK(comedy.get_nfunny_scenes() == 5);

        comedy.set_duration(6);
        CHECK(comedy.get_title() == "Manga");
        CHECK(comedy.get_price() == 200);
        CHECK(comedy.get_duration() == 6);
        CHECK(comedy.get_nfunny_scenes() == 5);

        comedy.set_title("Taraa");
        CHECK(comedy.get_title() == "Taraa");
        CHECK(comedy.get_price() == 200);
        CHECK(comedy.get_duration() == 6);
        CHECK(comedy.get_nfunny_scenes() == 5);

        comedy.set_nfunny_scenes(7);
        CHECK(comedy.get_title() == "Taraa");
        CHECK(comedy.get_price() == 200);
        CHECK(comedy.get_duration() == 6);
        CHECK(comedy.get_nfunny_scenes() == 7);
    }
}

TEST_CASE("drama simple tests")
{
    Drama drama1("Dasa", 90, 3, "double kill");

    CHECK(drama1.get_title() == "Dasa");
    CHECK(drama1.get_price() == 90);
    CHECK(drama1.get_duration() == 3);
    CHECK(drama1.get_main_drama_thread() == "double kill");

    SECTION("test setters")
    {
        drama1.set_title("Mala");
        drama1.set_price(100);
        drama1.set_duration(4);
        drama1.set_main_drama_thread("murder");

        CHECK(drama1.get_title() == "Mala");
        CHECK(drama1.get_price() == 100);
        CHECK(drama1.get_duration() == 4);
        CHECK(drama1.get_main_drama_thread() == "murder");
    }
}

TEST_CASE("tragedy simple tests")
{
    Tragedy tragedyy("Manga", 100, 10, "Mosa");

    CHECK(tragedyy.get_title() == "Manga");
    CHECK(tragedyy.get_price() == 100);
    CHECK(tragedyy.get_duration() == 10);
    CHECK(tragedyy.get_tragic_character_name() == "Mosa");

    SECTION("test setters")
    {
        tragedyy.set_price(200);
        CHECK(tragedyy.get_title() == "Manga");
        CHECK(tragedyy.get_price() == 200);
        CHECK(tragedyy.get_duration() == 10);
        CHECK(tragedyy.get_tragic_character_name() == "Mosa");

        tragedyy.set_duration(6);
        CHECK(tragedyy.get_title() == "Manga");
        CHECK(tragedyy.get_price() == 200);
        CHECK(tragedyy.get_duration() == 6);
        CHECK(tragedyy.get_tragic_character_name() == "Mosa");

        tragedyy.set_title("Taraa");
        CHECK(tragedyy.get_title() == "Taraa");
        CHECK(tragedyy.get_price() == 200);
        CHECK(tragedyy.get_duration() == 6);
        CHECK(tragedyy.get_tragic_character_name() == "Mosa");

        tragedyy.set_tragic_charactesr_name("Jaba");
        CHECK(tragedyy.get_title() == "Taraa");
        CHECK(tragedyy.get_price() == 200);
        CHECK(tragedyy.get_duration() == 6);
        CHECK(tragedyy.get_tragic_character_name() == "Jaba");
    }
}
