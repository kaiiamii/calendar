#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

int ifleap(int year);
int dayscount(int a);
int daysinamonth(int month, int year);
int howmanydays(int day, int month, int year);
int howmanydays_fromjes(int day, int month, int year);
int howmanydays_fromdate(int day, int month, int year, int day1, int month1, int year1);
int secweekday(int first, int difference);

int ifleap(int year) {
    bool res = 0;
    if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) {
        res = 1;
    }
    return res;
}

int dayscount(int year) {
    int days;
    bool res = ifleap(year);
    if (res == 1) {
        days = 366;
    }
    else {
        days = 365;
    }
    return days;
}

int daysinamonth(int month, int year) {
    int days_month = 0;
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
        days_month = 31;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11) {
        days_month = 30;
    }
    else if (month == 2) {
        days_month = 28 + ifleap(year);
    }
    return days_month;
}

int howmanydays(int day, int month, int year) {
    int count = day;
    int monthi = month;
    --monthi;
    while (monthi != 0) {
        count += daysinamonth(monthi, year);
        monthi--;
    }
    return count;
}

int howmanydays_fromjes(int day, int month, int year) {
    int daysi = howmanydays(day, month, year);
    for (int i = 1; i < year; ++i) {
        daysi += dayscount(i);
    }
    return daysi;
}

int howmanydays_fromdate(int day1, int month1, int year1, int day2, int month2, int year2) {
    int days_between_dates;
    if (howmanydays_fromjes(day1, month1, year1) <= howmanydays_fromjes(day2, month2, year2)) {
        days_between_dates = howmanydays_fromjes(day2, month2, year2) - howmanydays_fromjes(day1, month1, year1);
    }
    else {
        days_between_dates = howmanydays_fromjes(day1, month1, year1) - howmanydays_fromjes(day2, month2, year2);
    }
    return days_between_dates;
}

int secweekday(int weekday1, int difference) {
    int secday = (weekday1 + (difference % 7) + 7) % 7;
    return secday;
}

int main() {

    RenderWindow window(VideoMode(2300, 2000), "Calendar", Style::Default);

    int year = 2023, month = 1, day = 1, year1 = 2022, month13 = 12, day1 = 9, weekday = 4;

    Font font;
    font.loadFromFile("zi.ttf");
    Text txt("gi", font, 30);
    txt.setFillColor(Color::Black);
    txt.setStyle(Text::Bold);
    Text holiday("gi", font, 30);
    holiday.setFillColor(Color{ 178, 34, 34 });
    holiday.setStyle(Text::Bold);
    Text text("gi", font, 45);
    text.setFillColor(Color::Black);
    text.setStyle(Text::Bold);
    Text texti("gi", font, 78);
    texti.setFillColor(Color::Black);
    texti.setStyle(Text::Bold);
    CircleShape point(2.f);
    point.setFillColor(Color{ 178, 34, 34 });
    Text help("gi", font, 34);
    help.setFillColor(Color{ 242, 153, 153 });


    int month1 = 1, month2 = 2, month3 = 3, month4 = 4, month5 = 5, month6 = 6, month7 = 7, month8 = 8, month9 = 9, month10 = 10, month11 = 11, month12 = 12;
    int difference1 = howmanydays_fromdate(day, month1, year, day1, month13, year1);
    int difference2 = howmanydays_fromdate(day, month2, year, day1, month13, year1);
    int difference3 = howmanydays_fromdate(day, month3, year, day1, month13, year1);
    int difference4 = howmanydays_fromdate(day, month4, year, day1, month13, year1);
    int difference5 = howmanydays_fromdate(day, month5, year, day1, month13, year1);
    int difference6 = howmanydays_fromdate(day, month6, year, day1, month13, year1);
    int difference7 = howmanydays_fromdate(day, month7, year, day1, month13, year1);
    int difference8 = howmanydays_fromdate(day, month8, year, day1, month13, year1);
    int difference9 = howmanydays_fromdate(day, month9, year, day1, month13, year1);
    int difference10 = howmanydays_fromdate(day, month10, year, day1, month13, year1);
    int difference11 = howmanydays_fromdate(day, month11, year, day1, month13, year1);
    int difference12 = howmanydays_fromdate(day, month12, year, day1, month13, year1);
    


    int year_help = 0;
    int x = 1250, y = 1500, ishka = 10000000, count = 8;
    string number = "";
    
    window.clear(Color::White);

    for (int i = 28; i < 79; ++i) {
        point.setPosition(1200, i);
        window.draw(point);
        point.setPosition(1600, i);
        window.draw(point);
    }
    for (int i = 1200; i < 1600; ++i) {
        point.setPosition(i, 28);
        window.draw(point);
        point.setPosition(i, 79);
        window.draw(point);
    }

    for (int i = 180; i < 580; ++i) {
        point.setPosition(180, i);
        window.draw(point);
        point.setPosition(i + 40, 180);
        window.draw(point);
        point.setPosition(i, 180);
        window.draw(point);
        point.setPosition(620, i);
        window.draw(point);
        point.setPosition(i + 40, 580);
        window.draw(point);
        point.setPosition(i, 580);
        window.draw(point);
    }

    float x1 = 280;
    float y1 = 210;

    txt.setString("January");
    txt.setPosition(310, 130);
    window.draw(txt);

    txt.setString("Mo");
    txt.setPosition(210, 210);
    window.draw(txt);
    txt.setString("Tu");
    txt.setPosition(210, 260);
    window.draw(txt);
    txt.setString("We");
    txt.setPosition(210, 310);
    window.draw(txt);
    txt.setString("Th");
    txt.setPosition(210, 360);
    window.draw(txt);
    txt.setString("Fr");
    txt.setPosition(210, 410);
    window.draw(txt);
    txt.setString("Sa");
    txt.setPosition(210, 460);
    window.draw(txt);
    txt.setString("Su");
    txt.setPosition(210, 520);
    window.draw(txt);

    int s1 = (secweekday(weekday, difference1));
    int wday1 = (secweekday(weekday, difference1));

    while (s1 > 0) {
        y1 += 52;
        --s1;
    }

    int days1 = daysinamonth(month1, year);
    int day111 = 1;
    while (day111 <= days1) {
        if (wday1 != 6 && wday1 != 5) {
            if (day111 == 10) {
                x1 -= 10;
                txt.setString(to_string(day111));
                txt.setPosition(x1, y1);
                y1 += 52;
            }
            else {

                txt.setString(to_string(day111));
                txt.setPosition(x1, y1);
                y1 += 52;
            }
            window.draw(txt);
        }
        else if (wday1 == 5) {
            if (day111 == 10) {
                x1 -= 10;
                holiday.setString(to_string(day111));
                holiday.setPosition(x1, y1);
                y1 += 52;
            }
            else {
                holiday.setString(to_string(day111));
                holiday.setPosition(x1, y1);
                y1 += 52;
            }
            window.draw(holiday);
        }
        else {
            if (day111 == 10) {
                holiday.setString(to_string(day111));
                holiday.setPosition(x1, y1);
                y1 = 210;
                x1 += 50;
            }
            else {
                holiday.setString(to_string(day111));
                holiday.setPosition(x1, y1);
                y1 = 210;
                x1 += 60;
            }
            window.draw(holiday);
        }
        ++wday1;
        ++day111;
        wday1 %= 7;
    }

    for (int i = 680; i < 1080; ++i) {
        point.setPosition(680, i - 500);
        window.draw(point);
        point.setPosition(i + 40, 180);
        window.draw(point);
        point.setPosition(i, 180);
        window.draw(point);
        point.setPosition(1120, i - 500);
        window.draw(point);
        point.setPosition(i + 40, 580);
        window.draw(point);
        point.setPosition(i, 580);
        window.draw(point);
    }

    float x2 = 790;
    float y2 = 210;

    txt.setString("February");
    txt.setPosition(795, 130);
    window.draw(txt);

    txt.setString("Mo");
    txt.setPosition(710, 210);
    window.draw(txt);
    txt.setString("Tu");
    txt.setPosition(710, 260);
    window.draw(txt);
    txt.setString("We");
    txt.setPosition(710, 310);
    window.draw(txt);
    txt.setString("Th");
    txt.setPosition(710, 360);
    window.draw(txt);
    txt.setString("Fr");
    txt.setPosition(710, 410);
    window.draw(txt);
    txt.setString("Sa");
    txt.setPosition(710, 460);
    window.draw(txt);
    txt.setString("Su");
    txt.setPosition(710, 520);
    window.draw(txt);

    int s2 = (secweekday(weekday, difference2));
    int wday2 = (secweekday(weekday, difference2));

    while (s2 > 0) {
        y2 += 52;
        --s2;
    }

    int days2 = daysinamonth(month2, year);
    int day2 = 1;
    while (day2 <= days2) {
        if (wday2 != 6 && wday2 != 5) {
            if (day2 == 10) {
                x2 -= 10;
                txt.setString(to_string(day2));
                txt.setPosition(x2, y2);
                y2 += 52;
            }
            else {

                txt.setString(to_string(day2));
                txt.setPosition(x2, y2);
                y2 += 52;
            }
            window.draw(txt);
        }
        else if (wday2 == 5) {
            if (day2 == 10) {
                x2 -= 10;
                holiday.setString(to_string(day2));
                holiday.setPosition(x2, y2);
                y2 += 52;
            }
            else {
                holiday.setString(to_string(day2));
                holiday.setPosition(x2, y2);
                y2 += 52;
            }
            window.draw(holiday);
        }
        else {
            if (day2 == 10) {
                holiday.setString(to_string(day2));
                holiday.setPosition(x2, y2);
                y2 = 210;
                x2 += 50;
            }
            else {
                holiday.setString(to_string(day2));
                holiday.setPosition(x2, y2);
                y2 = 210;
                x2 += 60;
            }
            window.draw(holiday);
        }
        ++wday2;
        ++day2;
        wday2 %= 7;
    }

    for (int i = 1180; i < 1580; ++i) {
        point.setPosition(1180, i - 1000);
        window.draw(point);
        point.setPosition(i + 40, 180);
        window.draw(point);
        point.setPosition(i, 180);
        window.draw(point);
        point.setPosition(1620, i - 1000);
        window.draw(point);
        point.setPosition(i, 580);
        window.draw(point);
        point.setPosition(i + 40, 580);
        window.draw(point);
    }

    float x3 = 1290;
    float y3 = 210;

    txt.setString("March");
    txt.setPosition(1320, 130);
    window.draw(txt);

    txt.setString("Mo");
    txt.setPosition(1210, 210);
    window.draw(txt);
    txt.setString("Tu");
    txt.setPosition(1210, 260);
    window.draw(txt);
    txt.setString("We");
    txt.setPosition(1210, 310);
    window.draw(txt);
    txt.setString("Th");
    txt.setPosition(1210, 360);
    window.draw(txt);
    txt.setString("Fr");
    txt.setPosition(1210, 410);
    window.draw(txt);
    txt.setString("Sa");
    txt.setPosition(1210, 460);
    window.draw(txt);
    txt.setString("Su");
    txt.setPosition(1210, 520);
    window.draw(txt);

    int s3 = (secweekday(weekday, difference3));
    int wday3 = (secweekday(weekday, difference3));

    while (s3 > 0) {
        y3 += 52;
        --s3;
    }

    int days3 = daysinamonth(month3, year);
    int day3 = 1;
    while (day3 <= days3) {
        if (wday3 != 6 && wday3 != 5) {
            if (day3 == 10) {
                x3 -= 10;
                txt.setString(to_string(day3));
                txt.setPosition(x3, y3);
                y3 += 52;
            }
            else {

                txt.setString(to_string(day3));
                txt.setPosition(x3, y3);
                y3 += 52;
            }
            window.draw(txt);
        }
        else if (wday3 == 5) {
            if (day3 == 10) {
                x3 -= 10;
                holiday.setString(to_string(day3));
                holiday.setPosition(x3, y3);
                y3 += 52;
            }
            else {
                holiday.setString(to_string(day3));
                holiday.setPosition(x3, y3);
                y3 += 52;
            }
            window.draw(holiday);
        }
        else {
            if (day3 == 10) {
                holiday.setString(to_string(day3));
                holiday.setPosition(x3, y3);
                y3 = 210;
                x3 += 50;
            }
            else {
                holiday.setString(to_string(day3));
                holiday.setPosition(x3, y3);
                y3 = 210;
                x3 += 60;
            }
            window.draw(holiday);
        }
        ++wday3;
        ++day3;
        wday3 %= 7;
    }

    for (int i = 1680; i < 2080; ++i) {
        point.setPosition(1680, i - 1500);
        window.draw(point);
        point.setPosition(i + 40, 180);
        window.draw(point);
        point.setPosition(i, 180);
        window.draw(point);
        point.setPosition(2120, i - 1500);
        window.draw(point);
        point.setPosition(i, 580);
        window.draw(point);
        point.setPosition(i + 40, 580);
        window.draw(point);
    }

    float x4 = 1790;
    float y4 = 210;

    txt.setString("April");
    txt.setPosition(1820, 130);
    window.draw(txt);

    txt.setString("Mo");
    txt.setPosition(1710, 210);
    window.draw(txt);
    txt.setString("Tu");
    txt.setPosition(1710, 260);
    window.draw(txt);
    txt.setString("We");
    txt.setPosition(1710, 310);
    window.draw(txt);
    txt.setString("Th");
    txt.setPosition(1710, 360);
    window.draw(txt);
    txt.setString("Fr");
    txt.setPosition(1710, 410);
    window.draw(txt);
    txt.setString("Sa");
    txt.setPosition(1710, 460);
    window.draw(txt);
    txt.setString("Su");
    txt.setPosition(1710, 520);
    window.draw(txt);

    int s4 = (secweekday(weekday, difference4));
    int wday4 = (secweekday(weekday, difference4));

    while (s4 > 0) {
        y4 += 52;
        --s4;
    }

    int days4 = daysinamonth(month4, year);
    int day4 = 1;
    while (day4 <= days4) {
        if (wday4 != 6 && wday4 != 5) {
            if (day4 == 10) {
                x4 -= 10;
                txt.setString(to_string(day4));
                txt.setPosition(x4, y4);
                y4 += 52;
            }
            else {

                txt.setString(to_string(day4));
                txt.setPosition(x4, y4);
                y4 += 52;
            }
            window.draw(txt);
        }
        else if (wday4 == 5) {
            if (day4 == 10) {
                x4 -= 10;
                holiday.setString(to_string(day4));
                holiday.setPosition(x4, y4);
                y4 += 52;
            }
            else {
                holiday.setString(to_string(day4));
                holiday.setPosition(x4, y4);
                y4 += 52;
            }
            window.draw(holiday);
        }
        else {
            if (day4 == 10) {
                holiday.setString(to_string(day4));
                holiday.setPosition(x4, y4);
                y4 = 210;
                x4 += 50;
            }
            else {
                holiday.setString(to_string(day4));
                holiday.setPosition(x4, y4);
                y4 = 210;
                x4 += 60;
            }
            window.draw(holiday);
        }
        ++wday4;
        ++day4;
        wday4 %= 7;
    }

    //второй блок

    for (int i = 180; i < 580; ++i) {
        point.setPosition(180, i + 500);
        window.draw(point);
        point.setPosition(i + 40, 180 + 500);
        window.draw(point);
        point.setPosition(i, 180 + 500);
        window.draw(point);
        point.setPosition(620, i + 500);
        window.draw(point);
        point.setPosition(i + 40, 580 + 500);
        window.draw(point);
        point.setPosition(i, 580 + 500);
        window.draw(point);
    }

    float x5 = 290;
    float y5 = 710;

    txt.setString("May");
    txt.setPosition(350, 630);
    window.draw(txt);

    txt.setString("Mo");
    txt.setPosition(210, 710);
    window.draw(txt);
    txt.setString("Tu");
    txt.setPosition(210, 760);
    window.draw(txt);
    txt.setString("We");
    txt.setPosition(210, 810);
    window.draw(txt);
    txt.setString("Th");
    txt.setPosition(210, 860);
    window.draw(txt);
    txt.setString("Fr");
    txt.setPosition(210, 910);
    window.draw(txt);
    txt.setString("Sa");
    txt.setPosition(210, 960);
    window.draw(txt);
    txt.setString("Su");
    txt.setPosition(210, 1020);
    window.draw(txt);

    int s5 = (secweekday(weekday, difference5));
    int wday5 = (secweekday(weekday, difference5));

    while (s5 > 0) {
        y5 += 52;
        --s5;
    }

    int days5 = daysinamonth(month5, year);
    int day5 = 1;
    while (day5 <= days5) {
        if (wday5 != 6 && wday5 != 5) {
            if (day5 == 10) {
                x5 -= 10;
                txt.setString(to_string(day5));
                txt.setPosition(x5, y5);
                y5 += 52;
            }
            else {

                txt.setString(to_string(day5));
                txt.setPosition(x5, y5);
                y5 += 52;
            }
            window.draw(txt);
        }
        else if (wday5 == 5) {
            if (day5 == 10) {
                x5 -= 10;
                holiday.setString(to_string(day5));
                holiday.setPosition(x5, y5);
                y5 += 52;
            }
            else {
                holiday.setString(to_string(day5));
                holiday.setPosition(x5, y5);
                y5 += 52;
            }
            window.draw(holiday);
        }
        else {
            if (day5 == 10) {
                holiday.setString(to_string(day5));
                holiday.setPosition(x5, y5);
                y5 = 710;
                x5 += 50;
            }
            else {
                holiday.setString(to_string(day5));
                holiday.setPosition(x5, y5);
                y5 = 710;
                x5 += 60;
            }
            window.draw(holiday);
        }

        ++wday5;
        ++day5;
        wday5 %= 7;
    }

    for (int i = 680; i < 1080; ++i) {
        point.setPosition(680, i);
        window.draw(point);
        point.setPosition(i + 40, 180 + 500);
        window.draw(point);
        point.setPosition(i, 180 + 500);
        window.draw(point);
        point.setPosition(1120, i);
        window.draw(point);
        point.setPosition(i + 40, 580 + 500);
        window.draw(point);
        point.setPosition(i, 580 + 500);
        window.draw(point);
    }

    float x6 = 790;
    float y6 = 710;

    txt.setString("June");
    txt.setPosition(860, 630);
    window.draw(txt);

    txt.setString("Mo");
    txt.setPosition(710, 710);
    window.draw(txt);
    txt.setString("Tu");
    txt.setPosition(710, 760);
    window.draw(txt);
    txt.setString("We");
    txt.setPosition(710, 810);
    window.draw(txt);
    txt.setString("Th");
    txt.setPosition(710, 860);
    window.draw(txt);
    txt.setString("Fr");
    txt.setPosition(710, 910);
    window.draw(txt);
    txt.setString("Sa");
    txt.setPosition(710, 960);
    window.draw(txt);
    txt.setString("Su");
    txt.setPosition(710, 1020);
    window.draw(txt);

    int s6 = (secweekday(weekday, difference6));
    int wday6 = (secweekday(weekday, difference6));

    while (s6 > 0) {
        y6 += 52;
        --s6;
    }

    int days6 = daysinamonth(month6, year);
    int day6 = 1;
    while (day6 <= days6) {
        if (wday6 != 6 && wday6 != 5) {
            if (day6 == 10) {
                x6 -= 10;
                txt.setString(to_string(day6));
                txt.setPosition(x6, y6);
                y6 += 53;
            }
            else {

                txt.setString(to_string(day6));
                txt.setPosition(x6, y6);
                y6 += 53;
            }
            window.draw(txt);
        }
        else if (wday6 == 5) {
            if (day6 == 10) {
                x6 -= 10;
                holiday.setString(to_string(day6));
                holiday.setPosition(x6, y6);
                y6 += 52;
            }
            else {
                holiday.setString(to_string(day6));
                holiday.setPosition(x6, y6);
                y6 += 52;
            }
            window.draw(holiday);
        }
        else {
            if (day6 == 10) {
                holiday.setString(to_string(day6));
                holiday.setPosition(x6, y6);
                y6 = 710;
                x6 += 50;
            }
            else {
                holiday.setString(to_string(day6));
                holiday.setPosition(x6, y6);
                y6 = 710;
                x6 += 60;
            }
            window.draw(holiday);
        }
        ++wday6;
        ++day6;
        wday6 %= 7;
    }

    for (int i = 1180; i < 1580; ++i) {
        point.setPosition(1180, i - 500);
        window.draw(point);
        point.setPosition(i + 40, 180 + 500);
        window.draw(point);
        point.setPosition(i, 180 + 500);
        window.draw(point);
        point.setPosition(1620, i - 500);
        window.draw(point);
        point.setPosition(i, 580 + 500);
        window.draw(point);
        point.setPosition(i + 40, 580 + 500);
        window.draw(point);
    }

    float x7 = 1290;
    float y7 = 710;

    txt.setString("July");
    txt.setPosition(1340, 630);
    window.draw(txt);

    txt.setString("Mo");
    txt.setPosition(1210, 710);
    window.draw(txt);
    txt.setString("Tu");
    txt.setPosition(1210, 760);
    window.draw(txt);
    txt.setString("We");
    txt.setPosition(1210, 810);
    window.draw(txt);
    txt.setString("Th");
    txt.setPosition(1210, 860);
    window.draw(txt);
    txt.setString("Fr");
    txt.setPosition(1210, 910);
    window.draw(txt);
    txt.setString("Sa");
    txt.setPosition(1210, 960);
    window.draw(txt);
    txt.setString("Su");
    txt.setPosition(1210, 1020);
    window.draw(txt);

    int s7 = (secweekday(weekday, difference7));
    int wday7 = (secweekday(weekday, difference7));

    while (s7 > 0) {
        y7 += 52;
        --s7;
    }

    int days7 = daysinamonth(month7, year);
    int day7 = 1;
    while (day7 <= days7) {
        if (wday7 != 6 && wday7 != 5) {
            if (day7 == 10) {
                x7 -= 10;
                txt.setString(to_string(day7));
                txt.setPosition(x7, y7);
                y7 += 52;
            }
            else {

                txt.setString(to_string(day7));
                txt.setPosition(x7, y7);
                y7 += 52;
            }
            window.draw(txt);
        }
        else if (wday7 == 5) {
            if (day7 == 10) {
                x7 -= 10;
                holiday.setString(to_string(day7));
                holiday.setPosition(x7, y7);
                y7 += 52;
            }
            else {
                holiday.setString(to_string(day7));
                holiday.setPosition(x7, y7);
                y7 += 52;
            }
            window.draw(holiday);
        }
        else {
            if (day7 == 10) {
                holiday.setString(to_string(day7));
                holiday.setPosition(x7, y7);
                y7 = 710;
                x7 += 50;
            }
            else {
                holiday.setString(to_string(day7));
                holiday.setPosition(x7, y7);
                y7 = 710;
                x7 += 60;
            }
            window.draw(holiday);
        }
        ++wday7;
        ++day7;
        wday7 %= 7;
    }

    for (int i = 1680; i < 2080; ++i) {
        point.setPosition(1680, i - 1000);
        window.draw(point);
        point.setPosition(i + 40, 180 + 500);
        window.draw(point);
        point.setPosition(i, 180 + 500);
        window.draw(point);
        point.setPosition(2120, i - 1000);
        window.draw(point);
        point.setPosition(i, 580 + 500);
        window.draw(point);
        point.setPosition(i + 40, 580 + 500);
        window.draw(point);
    }

    float x8 = 1790;
    float y8 = 710;

    txt.setString("August");
    txt.setPosition(1820, 630);
    window.draw(txt);

    txt.setString("Mo");
    txt.setPosition(1710, 710);
    window.draw(txt);
    txt.setString("Tu");
    txt.setPosition(1710, 760);
    window.draw(txt);
    txt.setString("We");
    txt.setPosition(1710, 810);
    window.draw(txt);
    txt.setString("Th");
    txt.setPosition(1710, 860);
    window.draw(txt);
    txt.setString("Fr");
    txt.setPosition(1710, 910);
    window.draw(txt);
    txt.setString("Sa");
    txt.setPosition(1710, 960);
    window.draw(txt);
    txt.setString("Su");
    txt.setPosition(1710, 1020);
    window.draw(txt);

    int s8 = (secweekday(weekday, difference8));
    int wday8 = (secweekday(weekday, difference8));

    while (s8 > 0) {
        y8 += 52;
        --s8;
    }

    int days8 = daysinamonth(month8, year);
    int day8 = 1;
    while (day8 <= days8) {
        if (wday8 != 6 && wday8 != 5) {
            if (day8 == 10) {
                x8 -= 10;
                txt.setString(to_string(day8));
                txt.setPosition(x8, y8);
                y8 += 52;
            }
            else {

                txt.setString(to_string(day8));
                txt.setPosition(x8, y8);
                y8 += 52;
            }
            window.draw(txt);
        }
        else if (wday8 == 5) {
            if (day8 == 10) {
                x8 -= 10;
                holiday.setString(to_string(day8));
                holiday.setPosition(x8, y8);
                y8 += 52;
            }
            else {
                holiday.setString(to_string(day8));
                holiday.setPosition(x8, y8);
                y8 += 52;
            }
            window.draw(holiday);
        }
        else {
            if (day8 == 10) {
                holiday.setString(to_string(day8));
                holiday.setPosition(x8, y8);
                y8 = 710;
                x8 += 50;
            }
            else {
                holiday.setString(to_string(day8));
                holiday.setPosition(x8, y8);
                y8 = 710;
                x8 += 60;
            }
            window.draw(holiday);
        }
        ++wday8;
        ++day8;
        wday8 %= 7;
    }

    //третий блок

    for (int i = 180; i < 580; ++i) {
        point.setPosition(180, i + 1000);
        window.draw(point);
        point.setPosition(i + 40, 180 + 1000);
        window.draw(point);
        point.setPosition(i, 180 + 1000);
        window.draw(point);
        point.setPosition(620, i + 1000);
        window.draw(point);
        point.setPosition(i + 40, 580 + 1000);
        window.draw(point);
        point.setPosition(i, 580 + 1000);
        window.draw(point);
    }

    float x9 = 290;
    float y9 = 1210;

    txt.setString("September");
    txt.setPosition(280, 1130);
    window.draw(txt);

    txt.setString("Mo");
    txt.setPosition(210, 1210);
    window.draw(txt);
    txt.setString("Tu");
    txt.setPosition(210, 1260);
    window.draw(txt);
    txt.setString("We");
    txt.setPosition(210, 1310);
    window.draw(txt);
    txt.setString("Th");
    txt.setPosition(210, 1360);
    window.draw(txt);
    txt.setString("Fr");
    txt.setPosition(210, 1410);
    window.draw(txt);
    txt.setString("Sa");
    txt.setPosition(210, 1460);
    window.draw(txt);
    txt.setString("Su");
    txt.setPosition(210, 1520);
    window.draw(txt);

    int s9 = (secweekday(weekday, difference9));
    int wday9 = (secweekday(weekday, difference9));

    while (s9 > 0) {
        y9 += 52;
        --s9;
    }

    int days9 = daysinamonth(month9, year);
    int day9 = 1;
    while (day9 <= days9) {
        if (wday9 != 6 && wday9 != 5) {
            if (day9 == 10) {
                x9 -= 10;
                txt.setString(to_string(day9));
                txt.setPosition(x9, y9);
                y9 += 52;
            }
            else if (days2 == 29 && day9 == 12) {
                holiday.setString(to_string(day9));
                holiday.setPosition(x9, y9);
                y9 += 52;
                window.draw(holiday);
            }
            else if (days2 == 28 && day9 == 13) {
                holiday.setString(to_string(day9));
                holiday.setPosition(x9, y9);
                y9 += 52;
                window.draw(holiday);
            }
            else {
                txt.setString(to_string(day9));
                txt.setPosition(x9, y9);
                y9 += 53;
            }
            window.draw(txt);
        }
        else if (wday9 == 5) {
            if (day9 == 10) {
                x9 -= 10;
                holiday.setString(to_string(day9));
                holiday.setPosition(x9, y9);
                y9 += 52;
            }
            else if (days2 == 29 && day9 == 12) {
                holiday.setString(to_string(day9));
                holiday.setPosition(x9, y9);
                y9 += 52;
            }
            else if (days2 == 28 && day9 == 13) {
                holiday.setString(to_string(day9));
                holiday.setPosition(x9, y9);
                y9 += 52;
            }
            else {
                holiday.setString(to_string(day9));
                holiday.setPosition(x9, y9);
                y9 += 52;
            }
            window.draw(holiday);
        }
        else {
            if (day9 == 10) {
                holiday.setString(to_string(day9));
                holiday.setPosition(x9, y9);
                y9 = 1210;
                x9 += 50;
            }
            else if (days2 == 29 && day9 == 12) {
                holiday.setString(to_string(day9));
                holiday.setPosition(x9, y9);
                y9 = 1210;
                x9 += 60;
            }
            else if (days2 == 28 && day9 == 13) {
                holiday.setString(to_string(day9));
                holiday.setPosition(x9, y9);
                y9 = 1210;
                x9 += 60;
            }
            else {
                holiday.setString(to_string(day9));
                holiday.setPosition(x9, y9);
                y9 = 1210;
                x9 += 60;
            }
            window.draw(holiday);
        }

        ++wday9;
        ++day9;
        wday9 %= 7;
    }

    for (int i = 680; i < 1080; ++i) {
        point.setPosition(680, i + 500);
        window.draw(point);
        point.setPosition(i + 40, 180 + 1000);
        window.draw(point);
        point.setPosition(i, 180 + 1000);
        window.draw(point);
        point.setPosition(1120, i + 500);
        window.draw(point);
        point.setPosition(i + 40, 580 + 1000);
        window.draw(point);
        point.setPosition(i, 580 + 1000);
        window.draw(point);
    }

    float x10 = 780;
    float y10 = 1210;

    txt.setString("October");
    txt.setPosition(800, 1130);
    window.draw(txt);

    txt.setString("Mo");
    txt.setPosition(710, 1210);
    window.draw(txt);
    txt.setString("Tu");
    txt.setPosition(710, 1260);
    window.draw(txt);
    txt.setString("We");
    txt.setPosition(710, 1310);
    window.draw(txt);
    txt.setString("Th");
    txt.setPosition(710, 1360);
    window.draw(txt);
    txt.setString("Fr");
    txt.setPosition(710, 1410);
    window.draw(txt);
    txt.setString("Sa");
    txt.setPosition(710, 1460);
    window.draw(txt);
    txt.setString("Su");
    txt.setPosition(710, 1520);
    window.draw(txt);

    int s10 = (secweekday(weekday, difference10));
    int wday10 = (secweekday(weekday, difference10));

    while (s10 > 0) {
        y10 += 52;
        --s10;
    }

    int days10 = daysinamonth(month10, year);
    int day10 = 1;
    while (day10 <= days10) {
        if (wday10 != 6 && wday10 != 5) {
            if (day10 == 10) {
                x10 -= 10;
                txt.setString(to_string(day10));
                txt.setPosition(x10, y10);
                y10 += 52;
            }
            else {

                txt.setString(to_string(day10));
                txt.setPosition(x10, y10);
                y10 += 52;
            }
            window.draw(txt);
        }
        else if (wday10 == 5) {
            if (day10 == 10) {
                x10 -= 10;
                holiday.setString(to_string(day10));
                holiday.setPosition(x10, y10);
                y10 += 52;
            }
            else {
                holiday.setString(to_string(day10));
                holiday.setPosition(x10, y10);
                y10 += 52;
            }
            window.draw(holiday);
        }
        else {
            if (day10 == 10) {
                holiday.setString(to_string(day10));
                holiday.setPosition(x10, y10);
                y10 = 1210;
                x10 += 50;
            }
            else {
                holiday.setString(to_string(day10));
                holiday.setPosition(x10, y10);
                y10 = 1210;
                x10 += 60;
            }
            window.draw(holiday);
        }

        ++wday10;
        ++day10;
        wday10 %= 7;
    }

    for (int i = 1180; i < 1580; ++i) {
        point.setPosition(1180, i);
        window.draw(point);
        point.setPosition(i + 40, 180 + 1000);
        window.draw(point);
        point.setPosition(i, 180 + 1000);
        window.draw(point);
        point.setPosition(1620, i);
        window.draw(point);
        point.setPosition(i + 40, 580 + 1000);
        window.draw(point);
        point.setPosition(i, 580 + 1000);
        window.draw(point);
    }

    float x11 = 1280;
    float y11 = 1210;

    txt.setString("November");
    txt.setPosition(1300, 1130);
    window.draw(txt);

    txt.setString("Mo");
    txt.setPosition(1210, 1210);
    window.draw(txt);
    txt.setString("Tu");
    txt.setPosition(1210, 1260);
    window.draw(txt);
    txt.setString("We");
    txt.setPosition(1210, 1310);
    window.draw(txt);
    txt.setString("Th");
    txt.setPosition(1210, 1360);
    window.draw(txt);
    txt.setString("Fr");
    txt.setPosition(1210, 1410);
    window.draw(txt);
    txt.setString("Sa");
    txt.setPosition(1210, 1460);
    window.draw(txt);
    txt.setString("Su");
    txt.setPosition(1210, 1520);
    window.draw(txt);

    int s11 = (secweekday(weekday, difference11));
    int wday11 = (secweekday(weekday, difference11));

    while (s11 > 0) {
        y11 += 52;
        --s11;
    }

    int days11 = daysinamonth(month11, year);
    int day11 = 1;
    while (day11 <= days11) {
        if (wday11 != 6 && wday11 != 5) {
            if (day11 == 10) {
                x11 -= 10;
                txt.setString(to_string(day11));
                txt.setPosition(x11, y11);
                y11 += 52;
            }
            else {

                txt.setString(to_string(day11));
                txt.setPosition(x11, y11);
                y11 += 52;
            }
            window.draw(txt);
        }
        else if (wday11 == 5) {
            if (day11 == 10) {
                x11 -= 10;
                holiday.setString(to_string(day11));
                holiday.setPosition(x11, y11);
                y11 += 52;
            }
            else {
                holiday.setString(to_string(day11));
                holiday.setPosition(x11, y11);
                y11 += 52;
            }
            window.draw(holiday);
        }
        else {
            if (day11 == 6) {
                holiday.setString(to_string(day11));
                holiday.setPosition(x11, y11);
                y11 = 1210;
                x11 += 50;
            }
            else {
                holiday.setString(to_string(day11));
                holiday.setPosition(x11, y11);
                y11 = 1210;
                x11 += 60;
            }
            window.draw(holiday);
        }

        ++wday11;
        ++day11;
        wday11 %= 7;
    }

    for (int i = 1680; i < 2080; ++i) {
        point.setPosition(1680, i - 500);
        window.draw(point);
        point.setPosition(i + 40, 180 + 1000);
        window.draw(point);
        point.setPosition(i, 180 + 1000);
        window.draw(point);
        point.setPosition(2120, i - 500);
        window.draw(point);
        point.setPosition(i + 40, 580 + 1000);
        window.draw(point);
        point.setPosition(i, 580 + 1000);
        window.draw(point);
    }

    float x12 = 1780;
    float y12 = 1210;

    txt.setString("December");
    txt.setPosition(1800, 1130);
    window.draw(txt);

    txt.setString("Mo");
    txt.setPosition(1710, 1210);
    window.draw(txt);
    txt.setString("Tu");
    txt.setPosition(1710, 1260);
    window.draw(txt);
    txt.setString("We");
    txt.setPosition(1710, 1310);
    window.draw(txt);
    txt.setString("Th");
    txt.setPosition(1710, 1360);
    window.draw(txt);
    txt.setString("Fr");
    txt.setPosition(1710, 1410);
    window.draw(txt);
    txt.setString("Sa");
    txt.setPosition(1710, 1460);
    window.draw(txt);
    txt.setString("Su");
    txt.setPosition(1710, 1520);
    window.draw(txt);

    int s12 = (secweekday(weekday, difference12));
    int wday12 = (secweekday(weekday, difference12));

    while (s12 > 0) {
        y12 += 52;
        --s12;
    }

    int days12 = daysinamonth(month12, year);
    int day12 = 1;
    while (day12 <= days12) {
        if (wday12 != 6 && wday12 != 5) {
            if (day12 == 10) {
                x12 -= 10;
                txt.setString(to_string(day12));
                txt.setPosition(x12, y12);
                y12 += 52;
            }
            else {

                txt.setString(to_string(day12));
                txt.setPosition(x12, y12);
                y12 += 52;
            }
            window.draw(txt);
        }
        else if (wday12 == 5) {
            if (day12 == 10) {
                x12 -= 10;
                holiday.setString(to_string(day12));
                holiday.setPosition(x12, y12);
                y12 += 52;
            }
            else {
                holiday.setString(to_string(day12));
                holiday.setPosition(x12, y12);
                y12 += 52;
            }
            window.draw(holiday);
        }
        else {
            if (day12 == 6) {
                holiday.setString(to_string(day12));
                holiday.setPosition(x12, y12);
                y12 = 1210;
                x12 += 50;
            }
            else {
                holiday.setString(to_string(day12));
                holiday.setPosition(x12, y12);
                y12 = 1210;
                x12 += 60;
            }
            window.draw(holiday);
        }

        ++wday12;
        ++day12;
        wday12 %= 7;
    }

    text.setString("Calendar");
    text.setPosition(850, 30);
    window.draw(text);

    texti.setString(to_string(year));
    texti.setPosition(1100, 1670);
    window.draw(texti);
    window.display();

    while (window.isOpen()) {
        Event event;


       

        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
            if (event.type == Event::TextEntered && event.text.unicode >= 48 && event.text.unicode <= 58) {
                window.display();
                year_help += ishka * (event.text.unicode - 48);
                ishka /= 10;
                count--;
                number += to_string(event.text.unicode - 48);
                help.setString(number);
                help.setPosition(x, 30);
                window.draw(help);
                window.display();
            }
            if (event.type == Event::TextEntered && event.text.unicode == 13) {
                year = year_help / pow(10, count);
                count = 7;
                number = "";
                help.setString(number);
                help.setPosition(x, 30);
                window.draw(help);
                window.display();
                ishka = 1000000;
                year_help = 0;

                difference1 = howmanydays_fromdate(day, month1, year, day1, month13, year1);
                difference2 = howmanydays_fromdate(day, month2, year, day1, month13, year1);
                difference3 = howmanydays_fromdate(day, month3, year, day1, month13, year1);
                difference4 = howmanydays_fromdate(day, month4, year, day1, month13, year1);
                difference5 = howmanydays_fromdate(day, month5, year, day1, month13, year1);
                difference6 = howmanydays_fromdate(day, month6, year, day1, month13, year1);
                difference7 = howmanydays_fromdate(day, month7, year, day1, month13, year1);
                difference8 = howmanydays_fromdate(day, month8, year, day1, month13, year1);
                difference9 = howmanydays_fromdate(day, month9, year, day1, month13, year1);
                difference10 = howmanydays_fromdate(day, month10, year, day1, month13, year1);
                difference11 = howmanydays_fromdate(day, month11, year, day1, month13, year1);
                difference12 = howmanydays_fromdate(day, month12, year, day1, month13, year1);

                window.clear(Color::White);

                for (int i = 28; i < 79; ++i) {
                    point.setPosition(1200, i);
                    window.draw(point);
                    point.setPosition(1600, i);
                    window.draw(point);
                }
                for (int i = 1200; i < 1600; ++i) {
                    point.setPosition(i, 28);
                    window.draw(point);
                    point.setPosition(i, 79);
                    window.draw(point);
                }

                for (int i = 180; i < 580; ++i) {
                    point.setPosition(180, i);
                    window.draw(point);
                    point.setPosition(i + 40, 180);
                    window.draw(point);
                    point.setPosition(i, 180);
                    window.draw(point);
                    point.setPosition(620, i);
                    window.draw(point);
                    point.setPosition(i + 40, 580);
                    window.draw(point);
                    point.setPosition(i, 580);
                    window.draw(point);
                }

                x1 = 280;
                y1 = 210;

                txt.setString("January");
                txt.setPosition(310, 130);
                window.draw(txt);

                txt.setString("Mo");
                txt.setPosition(210, 210);
                window.draw(txt);
                txt.setString("Tu");
                txt.setPosition(210, 260);
                window.draw(txt);
                txt.setString("We");
                txt.setPosition(210, 310);
                window.draw(txt);
                txt.setString("Th");
                txt.setPosition(210, 360);
                window.draw(txt);
                txt.setString("Fr");
                txt.setPosition(210, 410);
                window.draw(txt);
                txt.setString("Sa");
                txt.setPosition(210, 460);
                window.draw(txt);
                txt.setString("Su");
                txt.setPosition(210, 520);
                window.draw(txt);

                s1 = (secweekday(weekday, difference1));
                wday1 = (secweekday(weekday, difference1));

                while (s1 > 0) {
                    y1 += 52;
                    --s1;
                }

                days1 = daysinamonth(month1, year);
                day111 = 1;
                while (day111 <= days1) {
                    if (wday1 != 6 && wday1 != 5) {
                        if (day111 == 10) {
                            x1 -= 10;
                            txt.setString(to_string(day111));
                            txt.setPosition(x1, y1);
                            y1 += 52;
                        }
                        else {

                            txt.setString(to_string(day111));
                            txt.setPosition(x1, y1);
                            y1 += 52;
                        }
                        window.draw(txt);
                    }
                    else if (wday1 == 5) {
                        if (day111 == 10) {
                            x1 -= 10;
                            holiday.setString(to_string(day111));
                            holiday.setPosition(x1, y1);
                            y1 += 52;
                        }
                        else {
                            holiday.setString(to_string(day111));
                            holiday.setPosition(x1, y1);
                            y1 += 52;
                        }
                        window.draw(holiday);
                    }
                    else {
                        if (day111 == 10) {
                            holiday.setString(to_string(day111));
                            holiday.setPosition(x1, y1);
                            y1 = 210;
                            x1 += 50;
                        }
                        else {
                            holiday.setString(to_string(day111));
                            holiday.setPosition(x1, y1);
                            y1 = 210;
                            x1 += 60;
                        }
                        window.draw(holiday);
                    }
                    ++wday1;
                    ++day111;
                    wday1 %= 7;
                }

                for (int i = 680; i < 1080; ++i) {
                    point.setPosition(680, i - 500);
                    window.draw(point);
                    point.setPosition(i + 40, 180);
                    window.draw(point);
                    point.setPosition(i, 180);
                    window.draw(point);
                    point.setPosition(1120, i - 500);
                    window.draw(point);
                    point.setPosition(i + 40, 580);
                    window.draw(point);
                    point.setPosition(i, 580);
                    window.draw(point);
                }

                x2 = 790;
                y2 = 210;

                txt.setString("February");
                txt.setPosition(795, 130);
                window.draw(txt);

                txt.setString("Mo");
                txt.setPosition(710, 210);
                window.draw(txt);
                txt.setString("Tu");
                txt.setPosition(710, 260);
                window.draw(txt);
                txt.setString("We");
                txt.setPosition(710, 310);
                window.draw(txt);
                txt.setString("Th");
                txt.setPosition(710, 360);
                window.draw(txt);
                txt.setString("Fr");
                txt.setPosition(710, 410);
                window.draw(txt);
                txt.setString("Sa");
                txt.setPosition(710, 460);
                window.draw(txt);
                txt.setString("Su");
                txt.setPosition(710, 520);
                window.draw(txt);

                s2 = (secweekday(weekday, difference2));
                wday2 = (secweekday(weekday, difference2));

                while (s2 > 0) {
                    y2 += 52;
                    --s2;
                }

                days2 = daysinamonth(month2, year);
                day2 = 1;
                while (day2 <= days2) {
                    if (wday2 != 6 && wday2 != 5) {
                        if (day2 == 10) {
                            x2 -= 10;
                            txt.setString(to_string(day2));
                            txt.setPosition(x2, y2);
                            y2 += 52;
                        }
                        else {

                            txt.setString(to_string(day2));
                            txt.setPosition(x2, y2);
                            y2 += 52;
                        }
                        window.draw(txt);
                    }
                    else if (wday2 == 5) {
                        if (day2 == 10) {
                            x2 -= 10;
                            holiday.setString(to_string(day2));
                            holiday.setPosition(x2, y2);
                            y2 += 52;
                        }
                        else {
                            holiday.setString(to_string(day2));
                            holiday.setPosition(x2, y2);
                            y2 += 52;
                        }
                        window.draw(holiday);
                    }
                    else {
                        if (day2 == 10) {
                            holiday.setString(to_string(day2));
                            holiday.setPosition(x2, y2);
                            y2 = 210;
                            x2 += 50;
                        }
                        else {
                            holiday.setString(to_string(day2));
                            holiday.setPosition(x2, y2);
                            y2 = 210;
                            x2 += 60;
                        }
                        window.draw(holiday);
                    }
                    ++wday2;
                    ++day2;
                    wday2 %= 7;
                }

                for (int i = 1180; i < 1580; ++i) {
                    point.setPosition(1180, i - 1000);
                    window.draw(point);
                    point.setPosition(i + 40, 180);
                    window.draw(point);
                    point.setPosition(i, 180);
                    window.draw(point);
                    point.setPosition(1620, i - 1000);
                    window.draw(point);
                    point.setPosition(i, 580);
                    window.draw(point);
                    point.setPosition(i + 40, 580);
                    window.draw(point);
                }

                x3 = 1290;
                y3 = 210;

                txt.setString("March");
                txt.setPosition(1320, 130);
                window.draw(txt);

                txt.setString("Mo");
                txt.setPosition(1210, 210);
                window.draw(txt);
                txt.setString("Tu");
                txt.setPosition(1210, 260);
                window.draw(txt);
                txt.setString("We");
                txt.setPosition(1210, 310);
                window.draw(txt);
                txt.setString("Th");
                txt.setPosition(1210, 360);
                window.draw(txt);
                txt.setString("Fr");
                txt.setPosition(1210, 410);
                window.draw(txt);
                txt.setString("Sa");
                txt.setPosition(1210, 460);
                window.draw(txt);
                txt.setString("Su");
                txt.setPosition(1210, 520);
                window.draw(txt);

                s3 = (secweekday(weekday, difference3));
                wday3 = (secweekday(weekday, difference3));

                while (s3 > 0) {
                    y3 += 52;
                    --s3;
                }

                days3 = daysinamonth(month3, year);
                day3 = 1;
                while (day3 <= days3) {
                    if (wday3 != 6 && wday3 != 5) {
                        if (day3 == 10) {
                            x3 -= 10;
                            txt.setString(to_string(day3));
                            txt.setPosition(x3, y3);
                            y3 += 52;
                        }
                        else {

                            txt.setString(to_string(day3));
                            txt.setPosition(x3, y3);
                            y3 += 52;
                        }
                        window.draw(txt);
                    }
                    else if (wday3 == 5) {
                        if (day3 == 10) {
                            x3 -= 10;
                            holiday.setString(to_string(day3));
                            holiday.setPosition(x3, y3);
                            y3 += 52;
                        }
                        else {
                            holiday.setString(to_string(day3));
                            holiday.setPosition(x3, y3);
                            y3 += 52;
                        }
                        window.draw(holiday);
                    }
                    else {
                        if (day3 == 10) {
                            holiday.setString(to_string(day3));
                            holiday.setPosition(x3, y3);
                            y3 = 210;
                            x3 += 50;
                        }
                        else {
                            holiday.setString(to_string(day3));
                            holiday.setPosition(x3, y3);
                            y3 = 210;
                            x3 += 60;
                        }
                        window.draw(holiday);
                    }
                    ++wday3;
                    ++day3;
                    wday3 %= 7;
                }

                for (int i = 1680; i < 2080; ++i) {
                    point.setPosition(1680, i - 1500);
                    window.draw(point);
                    point.setPosition(i + 40, 180);
                    window.draw(point);
                    point.setPosition(i, 180);
                    window.draw(point);
                    point.setPosition(2120, i - 1500);
                    window.draw(point);
                    point.setPosition(i, 580);
                    window.draw(point);
                    point.setPosition(i + 40, 580);
                    window.draw(point);
                }

                x4 = 1790;
                y4 = 210;

                txt.setString("April");
                txt.setPosition(1820, 130);
                window.draw(txt);

                txt.setString("Mo");
                txt.setPosition(1710, 210);
                window.draw(txt);
                txt.setString("Tu");
                txt.setPosition(1710, 260);
                window.draw(txt);
                txt.setString("We");
                txt.setPosition(1710, 310);
                window.draw(txt);
                txt.setString("Th");
                txt.setPosition(1710, 360);
                window.draw(txt);
                txt.setString("Fr");
                txt.setPosition(1710, 410);
                window.draw(txt);
                txt.setString("Sa");
                txt.setPosition(1710, 460);
                window.draw(txt);
                txt.setString("Su");
                txt.setPosition(1710, 520);
                window.draw(txt);

                s4 = (secweekday(weekday, difference4));
                wday4 = (secweekday(weekday, difference4));

                while (s4 > 0) {
                    y4 += 52;
                    --s4;
                }

                days4 = daysinamonth(month4, year);
                day4 = 1;
                while (day4 <= days4) {
                    if (wday4 != 6 && wday4 != 5) {
                        if (day4 == 10) {
                            x4 -= 10;
                            txt.setString(to_string(day4));
                            txt.setPosition(x4, y4);
                            y4 += 52;
                        }
                        else {

                            txt.setString(to_string(day4));
                            txt.setPosition(x4, y4);
                            y4 += 52;
                        }
                        window.draw(txt);
                    }
                    else if (wday4 == 5) {
                        if (day4 == 10) {
                            x4 -= 10;
                            holiday.setString(to_string(day4));
                            holiday.setPosition(x4, y4);
                            y4 += 52;
                        }
                        else {
                            holiday.setString(to_string(day4));
                            holiday.setPosition(x4, y4);
                            y4 += 52;
                        }
                        window.draw(holiday);
                    }
                    else {
                        if (day4 == 10) {
                            holiday.setString(to_string(day4));
                            holiday.setPosition(x4, y4);
                            y4 = 210;
                            x4 += 50;
                        }
                        else {
                            holiday.setString(to_string(day4));
                            holiday.setPosition(x4, y4);
                            y4 = 210;
                            x4 += 60;
                        }
                        window.draw(holiday);
                    }
                    ++wday4;
                    ++day4;
                    wday4 %= 7;
                }

                //второй блок

                for (int i = 180; i < 580; ++i) {
                    point.setPosition(180, i + 500);
                    window.draw(point);
                    point.setPosition(i + 40, 180 + 500);
                    window.draw(point);
                    point.setPosition(i, 180 + 500);
                    window.draw(point);
                    point.setPosition(620, i + 500);
                    window.draw(point);
                    point.setPosition(i + 40, 580 + 500);
                    window.draw(point);
                    point.setPosition(i, 580 + 500);
                    window.draw(point);
                }

                x5 = 290;
                y5 = 710;

                txt.setString("May");
                txt.setPosition(350, 630);
                window.draw(txt);

                txt.setString("Mo");
                txt.setPosition(210, 710);
                window.draw(txt);
                txt.setString("Tu");
                txt.setPosition(210, 760);
                window.draw(txt);
                txt.setString("We");
                txt.setPosition(210, 810);
                window.draw(txt);
                txt.setString("Th");
                txt.setPosition(210, 860);
                window.draw(txt);
                txt.setString("Fr");
                txt.setPosition(210, 910);
                window.draw(txt);
                txt.setString("Sa");
                txt.setPosition(210, 960);
                window.draw(txt);
                txt.setString("Su");
                txt.setPosition(210, 1020);
                window.draw(txt);

                s5 = (secweekday(weekday, difference5));
                wday5 = (secweekday(weekday, difference5));

                while (s5 > 0) {
                    y5 += 52;
                    --s5;
                }

                days5 = daysinamonth(month5, year);
                day5 = 1;
                while (day5 <= days5) {
                    if (wday5 != 6 && wday5 != 5) {
                        if (day5 == 10) {
                            x5 -= 10;
                            txt.setString(to_string(day5));
                            txt.setPosition(x5, y5);
                            y5 += 52;
                        }
                        else {

                            txt.setString(to_string(day5));
                            txt.setPosition(x5, y5);
                            y5 += 52;
                        }
                        window.draw(txt);
                    }
                    else if (wday5 == 5) {
                        if (day5 == 10) {
                            x5 -= 10;
                            holiday.setString(to_string(day5));
                            holiday.setPosition(x5, y5);
                            y5 += 52;
                        }
                        else {
                            holiday.setString(to_string(day5));
                            holiday.setPosition(x5, y5);
                            y5 += 52;
                        }
                        window.draw(holiday);
                    }
                    else {
                        if (day5 == 10) {
                            holiday.setString(to_string(day5));
                            holiday.setPosition(x5, y5);
                            y5 = 710;
                            x5 += 50;
                        }
                        else {
                            holiday.setString(to_string(day5));
                            holiday.setPosition(x5, y5);
                            y5 = 710;
                            x5 += 60;
                        }
                        window.draw(holiday);
                    }

                    ++wday5;
                    ++day5;
                    wday5 %= 7;
                }

                for (int i = 680; i < 1080; ++i) {
                    point.setPosition(680, i);
                    window.draw(point);
                    point.setPosition(i + 40, 180 + 500);
                    window.draw(point);
                    point.setPosition(i, 180 + 500);
                    window.draw(point);
                    point.setPosition(1120, i);
                    window.draw(point);
                    point.setPosition(i + 40, 580 + 500);
                    window.draw(point);
                    point.setPosition(i, 580 + 500);
                    window.draw(point);
                }

                x6 = 790;
                y6 = 710;

                txt.setString("June");
                txt.setPosition(860, 630);
                window.draw(txt);

                txt.setString("Mo");
                txt.setPosition(710, 710);
                window.draw(txt);
                txt.setString("Tu");
                txt.setPosition(710, 760);
                window.draw(txt);
                txt.setString("We");
                txt.setPosition(710, 810);
                window.draw(txt);
                txt.setString("Th");
                txt.setPosition(710, 860);
                window.draw(txt);
                txt.setString("Fr");
                txt.setPosition(710, 910);
                window.draw(txt);
                txt.setString("Sa");
                txt.setPosition(710, 960);
                window.draw(txt);
                txt.setString("Su");
                txt.setPosition(710, 1020);
                window.draw(txt);

                s6 = (secweekday(weekday, difference6));
                wday6 = (secweekday(weekday, difference6));

                while (s6 > 0) {
                    y6 += 52;
                    --s6;
                }

                days6 = daysinamonth(month6, year);
                day6 = 1;
                while (day6 <= days6) {
                    if (wday6 != 6 && wday6 != 5) {
                        if (day6 == 10) {
                            x6 -= 10;
                            txt.setString(to_string(day6));
                            txt.setPosition(x6, y6);
                            y6 += 53;
                        }
                        else {

                            txt.setString(to_string(day6));
                            txt.setPosition(x6, y6);
                            y6 += 53;
                        }
                        window.draw(txt);
                    }
                    else if (wday6 == 5) {
                        if (day6 == 10) {
                            x6 -= 10;
                            holiday.setString(to_string(day6));
                            holiday.setPosition(x6, y6);
                            y6 += 52;
                        }
                        else {
                            holiday.setString(to_string(day6));
                            holiday.setPosition(x6, y6);
                            y6 += 52;
                        }
                        window.draw(holiday);
                    }
                    else {
                        if (day6 == 10) {
                            holiday.setString(to_string(day6));
                            holiday.setPosition(x6, y6);
                            y6 = 710;
                            x6 += 50;
                        }
                        else {
                            holiday.setString(to_string(day6));
                            holiday.setPosition(x6, y6);
                            y6 = 710;
                            x6 += 60;
                        }
                        window.draw(holiday);
                    }
                    ++wday6;
                    ++day6;
                    wday6 %= 7;
                }

                for (int i = 1180; i < 1580; ++i) {
                    point.setPosition(1180, i - 500);
                    window.draw(point);
                    point.setPosition(i + 40, 180 + 500);
                    window.draw(point);
                    point.setPosition(i, 180 + 500);
                    window.draw(point);
                    point.setPosition(1620, i - 500);
                    window.draw(point);
                    point.setPosition(i, 580 + 500);
                    window.draw(point);
                    point.setPosition(i + 40, 580 + 500);
                    window.draw(point);
                }

                x7 = 1290;
                y7 = 710;

                txt.setString("July");
                txt.setPosition(1340, 630);
                window.draw(txt);

                txt.setString("Mo");
                txt.setPosition(1210, 710);
                window.draw(txt);
                txt.setString("Tu");
                txt.setPosition(1210, 760);
                window.draw(txt);
                txt.setString("We");
                txt.setPosition(1210, 810);
                window.draw(txt);
                txt.setString("Th");
                txt.setPosition(1210, 860);
                window.draw(txt);
                txt.setString("Fr");
                txt.setPosition(1210, 910);
                window.draw(txt);
                txt.setString("Sa");
                txt.setPosition(1210, 960);
                window.draw(txt);
                txt.setString("Su");
                txt.setPosition(1210, 1020);
                window.draw(txt);

                s7 = (secweekday(weekday, difference7));
                wday7 = (secweekday(weekday, difference7));

                while (s7 > 0) {
                    y7 += 52;
                    --s7;
                }

                days7 = daysinamonth(month7, year);
                day7 = 1;
                while (day7 <= days7) {
                    if (wday7 != 6 && wday7 != 5) {
                        if (day7 == 10) {
                            x7 -= 10;
                            txt.setString(to_string(day7));
                            txt.setPosition(x7, y7);
                            y7 += 52;
                        }
                        else {

                            txt.setString(to_string(day7));
                            txt.setPosition(x7, y7);
                            y7 += 52;
                        }
                        window.draw(txt);
                    }
                    else if (wday7 == 5) {
                        if (day7 == 10) {
                            x7 -= 10;
                            holiday.setString(to_string(day7));
                            holiday.setPosition(x7, y7);
                            y7 += 52;
                        }
                        else {
                            holiday.setString(to_string(day7));
                            holiday.setPosition(x7, y7);
                            y7 += 52;
                        }
                        window.draw(holiday);
                    }
                    else {
                        if (day7 == 10) {
                            holiday.setString(to_string(day7));
                            holiday.setPosition(x7, y7);
                            y7 = 710;
                            x7 += 50;
                        }
                        else {
                            holiday.setString(to_string(day7));
                            holiday.setPosition(x7, y7);
                            y7 = 710;
                            x7 += 60;
                        }
                        window.draw(holiday);
                    }
                    ++wday7;
                    ++day7;
                    wday7 %= 7;
                }

                for (int i = 1680; i < 2080; ++i) {
                    point.setPosition(1680, i - 1000);
                    window.draw(point);
                    point.setPosition(i + 40, 180 + 500);
                    window.draw(point);
                    point.setPosition(i, 180 + 500);
                    window.draw(point);
                    point.setPosition(2120, i - 1000);
                    window.draw(point);
                    point.setPosition(i, 580 + 500);
                    window.draw(point);
                    point.setPosition(i + 40, 580 + 500);
                    window.draw(point);
                }

                x8 = 1790;
                y8 = 710;

                txt.setString("August");
                txt.setPosition(1820, 630);
                window.draw(txt);

                txt.setString("Mo");
                txt.setPosition(1710, 710);
                window.draw(txt);
                txt.setString("Tu");
                txt.setPosition(1710, 760);
                window.draw(txt);
                txt.setString("We");
                txt.setPosition(1710, 810);
                window.draw(txt);
                txt.setString("Th");
                txt.setPosition(1710, 860);
                window.draw(txt);
                txt.setString("Fr");
                txt.setPosition(1710, 910);
                window.draw(txt);
                txt.setString("Sa");
                txt.setPosition(1710, 960);
                window.draw(txt);
                txt.setString("Su");
                txt.setPosition(1710, 1020);
                window.draw(txt);

                s8 = (secweekday(weekday, difference8));
                wday8 = (secweekday(weekday, difference8));

                while (s8 > 0) {
                    y8 += 52;
                    --s8;
                }

                days8 = daysinamonth(month8, year);
                day8 = 1;
                while (day8 <= days8) {
                    if (wday8 != 6 && wday8 != 5) {
                        if (day8 == 10) {
                            x8 -= 10;
                            txt.setString(to_string(day8));
                            txt.setPosition(x8, y8);
                            y8 += 52;
                        }
                        else {

                            txt.setString(to_string(day8));
                            txt.setPosition(x8, y8);
                            y8 += 52;
                        }
                        window.draw(txt);
                    }
                    else if (wday8 == 5) {
                        if (day8 == 10) {
                            x8 -= 10;
                            holiday.setString(to_string(day8));
                            holiday.setPosition(x8, y8);
                            y8 += 52;
                        }
                        else {
                            holiday.setString(to_string(day8));
                            holiday.setPosition(x8, y8);
                            y8 += 52;
                        }
                        window.draw(holiday);
                    }
                    else {
                        if (day8 == 10) {
                            holiday.setString(to_string(day8));
                            holiday.setPosition(x8, y8);
                            y8 = 710;
                            x8 += 50;
                        }
                        else {
                            holiday.setString(to_string(day8));
                            holiday.setPosition(x8, y8);
                            y8 = 710;
                            x8 += 60;
                        }
                        window.draw(holiday);
                    }
                    ++wday8;
                    ++day8;
                    wday8 %= 7;
                }

                //третий блок

                for (int i = 180; i < 580; ++i) {
                    point.setPosition(180, i + 1000);
                    window.draw(point);
                    point.setPosition(i + 40, 180 + 1000);
                    window.draw(point);
                    point.setPosition(i, 180 + 1000);
                    window.draw(point);
                    point.setPosition(620, i + 1000);
                    window.draw(point);
                    point.setPosition(i + 40, 580 + 1000);
                    window.draw(point);
                    point.setPosition(i, 580 + 1000);
                    window.draw(point);
                }

                x9 = 290;
                y9 = 1210;

                txt.setString("September");
                txt.setPosition(280, 1130);
                window.draw(txt);

                txt.setString("Mo");
                txt.setPosition(210, 1210);
                window.draw(txt);
                txt.setString("Tu");
                txt.setPosition(210, 1260);
                window.draw(txt);
                txt.setString("We");
                txt.setPosition(210, 1310);
                window.draw(txt);
                txt.setString("Th");
                txt.setPosition(210, 1360);
                window.draw(txt);
                txt.setString("Fr");
                txt.setPosition(210, 1410);
                window.draw(txt);
                txt.setString("Sa");
                txt.setPosition(210, 1460);
                window.draw(txt);
                txt.setString("Su");
                txt.setPosition(210, 1520);
                window.draw(txt);

                s9 = (secweekday(weekday, difference9));
                wday9 = (secweekday(weekday, difference9));

                while (s9 > 0) {
                    y9 += 52;
                    --s9;
                }

                days9 = daysinamonth(month9, year);
                day9 = 1;
                while (day9 <= days9) {
                    if (wday9 != 6 && wday9 != 5) {
                        if (day9 == 10) {
                            x9 -= 10;
                            txt.setString(to_string(day9));
                            txt.setPosition(x9, y9);
                            y9 += 52;
                        }
                        else if (days2 == 29 && day9 == 12) {
                            holiday.setString(to_string(day9));
                            holiday.setPosition(x9, y9);
                            y9 += 52;
                            window.draw(holiday);
                        }
                        else if (days2 == 28 && day9 == 13) {
                            holiday.setString(to_string(day9));
                            holiday.setPosition(x9, y9);
                            y9 += 52;
                            window.draw(holiday);
                        }
                        else {
                            txt.setString(to_string(day9));
                            txt.setPosition(x9, y9);
                            y9 += 52;
                        }
                        window.draw(txt);
                    }
                    else if (wday9 == 5) {
                        if (day9 == 10) {
                            x9 -= 10;
                            holiday.setString(to_string(day9));
                            holiday.setPosition(x9, y9);
                            y9 += 52;
                        }
                        else {
                            holiday.setString(to_string(day9));
                            holiday.setPosition(x9, y9);
                            y9 += 52;
                        }
                        window.draw(holiday);
                    }
                    else {
                        if (day9 == 10) {
                            holiday.setString(to_string(day9));
                            holiday.setPosition(x9, y9);
                            y9 = 1210;
                            x9 += 50;
                        }
                        else {
                            holiday.setString(to_string(day9));
                            holiday.setPosition(x9, y9);
                            y9 = 1210;
                            x9 += 60;
                        }
                        window.draw(holiday);
                    }

                    ++wday9;
                    ++day9;
                    wday9 %= 7;
                }

                for (int i = 680; i < 1080; ++i) {
                    point.setPosition(680, i + 500);
                    window.draw(point);
                    point.setPosition(i + 40, 180 + 1000);
                    window.draw(point);
                    point.setPosition(i, 180 + 1000);
                    window.draw(point);
                    point.setPosition(1120, i + 500);
                    window.draw(point);
                    point.setPosition(i + 40, 580 + 1000);
                    window.draw(point);
                    point.setPosition(i, 580 + 1000);
                    window.draw(point);
                }

                x10 = 780;
                y10 = 1210;

                txt.setString("October");
                txt.setPosition(800, 1130);
                window.draw(txt);

                txt.setString("Mo");
                txt.setPosition(710, 1210);
                window.draw(txt);
                txt.setString("Tu");
                txt.setPosition(710, 1260);
                window.draw(txt);
                txt.setString("We");
                txt.setPosition(710, 1310);
                window.draw(txt);
                txt.setString("Th");
                txt.setPosition(710, 1360);
                window.draw(txt);
                txt.setString("Fr");
                txt.setPosition(710, 1410);
                window.draw(txt);
                txt.setString("Sa");
                txt.setPosition(710, 1460);
                window.draw(txt);
                txt.setString("Su");
                txt.setPosition(710, 1520);
                window.draw(txt);

                s10 = (secweekday(weekday, difference10));
                wday10 = (secweekday(weekday, difference10));

                while (s10 > 0) {
                    y10 += 52;
                    --s10;
                }

                days10 = daysinamonth(month10, year);
                day10 = 1;
                while (day10 <= days10) {
                    if (wday10 != 6 && wday10 != 5) {
                        if (day10 == 10) {
                            x10 -= 10;
                            txt.setString(to_string(day10));
                            txt.setPosition(x10, y10);
                            y10 += 52;
                        }
                        else {

                            txt.setString(to_string(day10));
                            txt.setPosition(x10, y10);
                            y10 += 52;
                        }
                        window.draw(txt);
                    }
                    else if (wday10 == 5) {
                        if (day10 == 10) {
                            x10 -= 10;
                            holiday.setString(to_string(day10));
                            holiday.setPosition(x10, y10);
                            y10 += 52;
                        }
                        else {
                            holiday.setString(to_string(day10));
                            holiday.setPosition(x10, y10);
                            y10 += 52;
                        }
                        window.draw(holiday);
                    }
                    else {
                        if (day10 == 10) {
                            holiday.setString(to_string(day10));
                            holiday.setPosition(x10, y10);
                            y10 = 1210;
                            x10 += 50;
                        }
                        else {
                            holiday.setString(to_string(day10));
                            holiday.setPosition(x10, y10);
                            y10 = 1210;
                            x10 += 60;
                        }
                        window.draw(holiday);
                    }

                    ++wday10;
                    ++day10;
                    wday10 %= 7;
                }

                for (int i = 1180; i < 1580; ++i) {
                    point.setPosition(1180, i);
                    window.draw(point);
                    point.setPosition(i + 40, 180 + 1000);
                    window.draw(point);
                    point.setPosition(i, 180 + 1000);
                    window.draw(point);
                    point.setPosition(1620, i);
                    window.draw(point);
                    point.setPosition(i + 40, 580 + 1000);
                    window.draw(point);
                    point.setPosition(i, 580 + 1000);
                    window.draw(point);
                }

                x11 = 1280;
                y11 = 1210;

                txt.setString("November");
                txt.setPosition(1300, 1130);
                window.draw(txt);

                txt.setString("Mo");
                txt.setPosition(1210, 1210);
                window.draw(txt);
                txt.setString("Tu");
                txt.setPosition(1210, 1260);
                window.draw(txt);
                txt.setString("We");
                txt.setPosition(1210, 1310);
                window.draw(txt);
                txt.setString("Th");
                txt.setPosition(1210, 1360);
                window.draw(txt);
                txt.setString("Fr");
                txt.setPosition(1210, 1410);
                window.draw(txt);
                txt.setString("Sa");
                txt.setPosition(1210, 1460);
                window.draw(txt);
                txt.setString("Su");
                txt.setPosition(1210, 1520);
                window.draw(txt);

                s11 = (secweekday(weekday, difference11));
                wday11 = (secweekday(weekday, difference11));

                while (s11 > 0) {
                    y11 += 52;
                    --s11;
                }

                days11 = daysinamonth(month11, year);
                day11 = 1;
                while (day11 <= days11) {
                    if (wday11 != 6 && wday11 != 5) {
                        if (day11 == 10) {
                            x11 -= 10;
                            txt.setString(to_string(day11));
                            txt.setPosition(x11, y11);
                            y11 += 52;
                        }
                        else {

                            txt.setString(to_string(day11));
                            txt.setPosition(x11, y11);
                            y11 += 52;
                        }
                        window.draw(txt);
                    }
                    else if (wday11 == 5) {
                        if (day11 == 10) {
                            x11 -= 10;
                            holiday.setString(to_string(day11));
                            holiday.setPosition(x11, y11);
                            y11 += 52;
                        }
                        else {
                            holiday.setString(to_string(day11));
                            holiday.setPosition(x11, y11);
                            y11 += 52;
                        }
                        window.draw(holiday);
                    }
                    else {
                        if (day11 == 6) {
                            holiday.setString(to_string(day11));
                            holiday.setPosition(x11, y11);
                            y11 = 1210;
                            x11 += 50;
                        }
                        else {
                            holiday.setString(to_string(day11));
                            holiday.setPosition(x11, y11);
                            y11 = 1210;
                            x11 += 60;
                        }
                        window.draw(holiday);
                    }

                    ++wday11;
                    ++day11;
                    wday11 %= 7;
                }

                for (int i = 1680; i < 2080; ++i) {
                    point.setPosition(1680, i - 500);
                    window.draw(point);
                    point.setPosition(i + 40, 180 + 1000);
                    window.draw(point);
                    point.setPosition(i, 180 + 1000);
                    window.draw(point);
                    point.setPosition(2120, i - 500);
                    window.draw(point);
                    point.setPosition(i + 40, 580 + 1000);
                    window.draw(point);
                    point.setPosition(i, 580 + 1000);
                    window.draw(point);
                }

                x12 = 1780;
                y12 = 1210;

                txt.setString("December");
                txt.setPosition(1800, 1130);
                window.draw(txt);

                txt.setString("Mo");
                txt.setPosition(1710, 1210);
                window.draw(txt);
                txt.setString("Tu");
                txt.setPosition(1710, 1260);
                window.draw(txt);
                txt.setString("We");
                txt.setPosition(1710, 1310);
                window.draw(txt);
                txt.setString("Th");
                txt.setPosition(1710, 1360);
                window.draw(txt);
                txt.setString("Fr");
                txt.setPosition(1710, 1410);
                window.draw(txt);
                txt.setString("Sa");
                txt.setPosition(1710, 1460);
                window.draw(txt);
                txt.setString("Su");
                txt.setPosition(1710, 1520);
                window.draw(txt);

                s12 = (secweekday(weekday, difference12));
                wday12 = (secweekday(weekday, difference12));

                while (s12 > 0) {
                    y12 += 52;
                    --s12;
                }

                days12 = daysinamonth(month12, year);
                day12 = 1;
                while (day12 <= days12) {
                    if (wday12 != 6 && wday12 != 5) {
                        if (day12 == 10) {
                            x12 -= 10;
                            txt.setString(to_string(day12));
                            txt.setPosition(x12, y12);
                            y12 += 52;
                        }
                        else {

                            txt.setString(to_string(day12));
                            txt.setPosition(x12, y12);
                            y12 += 52;
                        }
                        window.draw(txt);
                    }
                    else if (wday12 == 5) {
                        if (day12 == 10) {
                            x12 -= 10;
                            holiday.setString(to_string(day12));
                            holiday.setPosition(x12, y12);
                            y12 += 52;
                        }
                        else {
                            holiday.setString(to_string(day12));
                            holiday.setPosition(x12, y12);
                            y12 += 52;
                        }
                        window.draw(holiday);
                    }
                    else {
                        if (day12 == 6) {
                            holiday.setString(to_string(day12));
                            holiday.setPosition(x12, y12);
                            y12 = 1210;
                            x12 += 50;
                        }
                        else {
                            holiday.setString(to_string(day12));
                            holiday.setPosition(x12, y12);
                            y12 = 1210;
                            x12 += 60;
                        }
                        window.draw(holiday);
                    }

                    ++wday12;
                    ++day12;
                    wday12 %= 7;
                }

                text.setString("Calendar");
                text.setPosition(850, 30);
                window.draw(text);

                texti.setString(to_string(year));
                texti.setPosition(1100, 1670);
                window.draw(texti);

                window.display();

                break;
            }
        }

    }
    return 0;
}