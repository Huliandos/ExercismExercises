#include "meetup.h"

namespace meetup {
    scheduler::scheduler(boost::date_time::months_of_year month, int year){
        firstDayOfMonth = boost::gregorian::date(year, month, 1);
        lastDayOfMonth = boost::gregorian::date(year, month, 
            boost::gregorian::gregorian_calendar::end_of_month_day(year, month));
        thirteenthDayOfMonth = boost::gregorian::date(year, month, 13);
    }

    boost::gregorian::date scheduler::monteenth() const{
        return boost::gregorian::next_weekday(thirteenthDayOfMonth, boost::gregorian::greg_weekday(boost::date_time::Monday));
    }
    boost::gregorian::date scheduler::tuesteenth() const{
        return boost::gregorian::next_weekday(thirteenthDayOfMonth, boost::gregorian::greg_weekday(boost::date_time::Tuesday));
    }
    boost::gregorian::date scheduler::wednesteenth() const{
        return boost::gregorian::next_weekday(thirteenthDayOfMonth, boost::gregorian::greg_weekday(boost::date_time::Wednesday));
    }
    boost::gregorian::date scheduler::thursteenth() const{
        return boost::gregorian::next_weekday(thirteenthDayOfMonth, boost::gregorian::greg_weekday(boost::date_time::Thursday));
    }
    boost::gregorian::date scheduler::friteenth() const{
        return boost::gregorian::next_weekday(thirteenthDayOfMonth, boost::gregorian::greg_weekday(boost::date_time::Friday));
    }
    boost::gregorian::date scheduler::saturteenth() const{
        return boost::gregorian::next_weekday(thirteenthDayOfMonth, boost::gregorian::greg_weekday(boost::date_time::Saturday));
    }
    boost::gregorian::date scheduler::sunteenth() const{
        return boost::gregorian::next_weekday(thirteenthDayOfMonth, boost::gregorian::greg_weekday(boost::date_time::Sunday));
    }

    boost::gregorian::date scheduler::first_monday() const{
        return boost::gregorian::next_weekday(firstDayOfMonth, boost::gregorian::greg_weekday(boost::date_time::Monday));
    }
    boost::gregorian::date scheduler::first_tuesday() const{
        return boost::gregorian::next_weekday(firstDayOfMonth, boost::gregorian::greg_weekday(boost::date_time::Tuesday));
    }
    boost::gregorian::date scheduler::first_wednesday() const{
        return boost::gregorian::next_weekday(firstDayOfMonth, boost::gregorian::greg_weekday(boost::date_time::Wednesday));
    }
    boost::gregorian::date scheduler::first_thursday() const{
        return boost::gregorian::next_weekday(firstDayOfMonth, boost::gregorian::greg_weekday(boost::date_time::Thursday));
    }
    boost::gregorian::date scheduler::first_friday() const{
        return boost::gregorian::next_weekday(firstDayOfMonth, boost::gregorian::greg_weekday(boost::date_time::Friday));
    }
    boost::gregorian::date scheduler::first_saturday() const{
        return boost::gregorian::next_weekday(firstDayOfMonth, boost::gregorian::greg_weekday(boost::date_time::Saturday));
    }
    boost::gregorian::date scheduler::first_sunday() const{
        return boost::gregorian::next_weekday(firstDayOfMonth, boost::gregorian::greg_weekday(boost::date_time::Sunday));
    }

    boost::gregorian::date scheduler::second_monday() const{
        return boost::gregorian::next_weekday(firstDayOfMonth, boost::gregorian::greg_weekday(boost::date_time::Monday)) 
            + boost::gregorian::date_duration(7);
    }
    boost::gregorian::date scheduler::second_tuesday() const{
        return boost::gregorian::next_weekday(firstDayOfMonth, boost::gregorian::greg_weekday(boost::date_time::Tuesday)) +                 boost::gregorian::date_duration(7);
    }
    boost::gregorian::date scheduler::second_wednesday() const{
        return boost::gregorian::next_weekday(firstDayOfMonth, boost::gregorian::greg_weekday(boost::date_time::Wednesday)) 
            + boost::gregorian::date_duration(7);
    }
    boost::gregorian::date scheduler::second_thursday() const{
        return boost::gregorian::next_weekday(firstDayOfMonth, boost::gregorian::greg_weekday(boost::date_time::Thursday)) 
            + boost::gregorian::date_duration(7);
    }
    boost::gregorian::date scheduler::second_friday() const{
        return boost::gregorian::next_weekday(firstDayOfMonth, boost::gregorian::greg_weekday(boost::date_time::Friday)) 
            + boost::gregorian::date_duration(7);
    }
    boost::gregorian::date scheduler::second_saturday() const{
        return boost::gregorian::next_weekday(firstDayOfMonth, boost::gregorian::greg_weekday(boost::date_time::Saturday)) 
            + boost::gregorian::date_duration(7);
    }
    boost::gregorian::date scheduler::second_sunday() const{
        return boost::gregorian::next_weekday(firstDayOfMonth, boost::gregorian::greg_weekday(boost::date_time::Sunday)) 
            + boost::gregorian::date_duration(7);
    }

    boost::gregorian::date scheduler::third_monday() const{
        return boost::gregorian::next_weekday(firstDayOfMonth, boost::gregorian::greg_weekday(boost::date_time::Monday)) 
            + boost::gregorian::date_duration(14);
    }
    boost::gregorian::date scheduler::third_tuesday() const{
        return boost::gregorian::next_weekday(firstDayOfMonth, boost::gregorian::greg_weekday(boost::date_time::Tuesday)) 
            + boost::gregorian::date_duration(14);
    }
    boost::gregorian::date scheduler::third_wednesday() const{
        return boost::gregorian::next_weekday(firstDayOfMonth, boost::gregorian::greg_weekday(boost::date_time::Wednesday)) 
            + boost::gregorian::date_duration(14);
    }
    boost::gregorian::date scheduler::third_thursday() const{
        return boost::gregorian::next_weekday(firstDayOfMonth, boost::gregorian::greg_weekday(boost::date_time::Thursday)) 
            + boost::gregorian::date_duration(14);
    }
    boost::gregorian::date scheduler::third_friday() const{
        return boost::gregorian::next_weekday(firstDayOfMonth, boost::gregorian::greg_weekday(boost::date_time::Friday)) 
            + boost::gregorian::date_duration(14);
    }
    boost::gregorian::date scheduler::third_saturday() const{
        return boost::gregorian::next_weekday(firstDayOfMonth, boost::gregorian::greg_weekday(boost::date_time::Saturday)) 
            + boost::gregorian::date_duration(14);
    }
    boost::gregorian::date scheduler::third_sunday() const{
        return boost::gregorian::next_weekday(firstDayOfMonth, boost::gregorian::greg_weekday(boost::date_time::Sunday)) 
            + boost::gregorian::date_duration(14);
    }

    boost::gregorian::date scheduler::fourth_monday() const{
        return boost::gregorian::next_weekday(firstDayOfMonth, boost::gregorian::greg_weekday(boost::date_time::Monday)) 
            + boost::gregorian::date_duration(21);
    }
    boost::gregorian::date scheduler::fourth_tuesday() const{
        return boost::gregorian::next_weekday(firstDayOfMonth, boost::gregorian::greg_weekday(boost::date_time::Tuesday)) 
            + boost::gregorian::date_duration(21);
    }
    boost::gregorian::date scheduler::fourth_wednesday() const{
        return boost::gregorian::next_weekday(firstDayOfMonth, boost::gregorian::greg_weekday(boost::date_time::Wednesday)) 
            + boost::gregorian::date_duration(21);
    }
    boost::gregorian::date scheduler::fourth_thursday() const{
        return boost::gregorian::next_weekday(firstDayOfMonth, boost::gregorian::greg_weekday(boost::date_time::Thursday)) 
            + boost::gregorian::date_duration(21);
    }
    boost::gregorian::date scheduler::fourth_friday() const{
        return boost::gregorian::next_weekday(firstDayOfMonth, boost::gregorian::greg_weekday(boost::date_time::Friday)) 
            + boost::gregorian::date_duration(21);
    }
    boost::gregorian::date scheduler::fourth_saturday() const{
        return boost::gregorian::next_weekday(firstDayOfMonth, boost::gregorian::greg_weekday(boost::date_time::Saturday)) 
            + boost::gregorian::date_duration(21);
    }
    boost::gregorian::date scheduler::fourth_sunday() const{
        return boost::gregorian::next_weekday(firstDayOfMonth, boost::gregorian::greg_weekday(boost::date_time::Sunday)) 
            + boost::gregorian::date_duration(21);
    }

    boost::gregorian::date scheduler::last_monday() const{
        return boost::gregorian::previous_weekday(lastDayOfMonth, boost::gregorian::greg_weekday(boost::date_time::Monday));
    }
    boost::gregorian::date scheduler::last_tuesday() const{
        return boost::gregorian::previous_weekday(lastDayOfMonth, boost::gregorian::greg_weekday(boost::date_time::Tuesday));
    }
    boost::gregorian::date scheduler::last_wednesday() const{
        return boost::gregorian::previous_weekday(lastDayOfMonth, boost::gregorian::greg_weekday(boost::date_time::Wednesday));
    }
    boost::gregorian::date scheduler::last_thursday() const{
        return boost::gregorian::previous_weekday(lastDayOfMonth, boost::gregorian::greg_weekday(boost::date_time::Thursday));
    }
    boost::gregorian::date scheduler::last_friday() const{
        return boost::gregorian::previous_weekday(lastDayOfMonth, boost::gregorian::greg_weekday(boost::date_time::Friday));
    }
    boost::gregorian::date scheduler::last_saturday() const{
        return boost::gregorian::previous_weekday(lastDayOfMonth, boost::gregorian::greg_weekday(boost::date_time::Saturday));
    }
    boost::gregorian::date scheduler::last_sunday() const{
        return boost::gregorian::previous_weekday(lastDayOfMonth, boost::gregorian::greg_weekday(boost::date_time::Sunday));
    }
}  // namespace meetup
