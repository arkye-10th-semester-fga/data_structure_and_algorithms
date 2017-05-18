#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class student
{
public:
	unsigned int id;

	unsigned int begin_hours;
	unsigned int end_hours;

	bool is_marked;

	student(unsigned int sid, string bwd, unsigned int bwh,
		bool bhia, string ewd, unsigned int ewh, bool ehia) :
		id(sid),
		begin_week_day(bwd),
		begin_week_hours(bwh),
		begin_hours_is_am(bhia),
		end_week_day(ewd),
		end_week_hours(ewh),
		end_hours_is_am(ehia)
	{
		begin_hours = get_week_as_hours(false)
			+ get_hours_format_24(false);
		end_hours = get_week_as_hours(true)
			+ get_hours_format_24(true);
		is_marked = false;
	}

	student() {}

	void print_shift()
	{
		cout << "Student #" << id << ": ";
		cout << begin_week_day << " ";
		cout << begin_week_hours << " ";
		cout << print_am_or_pm(begin_hours_is_am) << " ";
		cout << end_week_day << " ";
		cout << end_week_hours << " ";
		cout << print_am_or_pm(end_hours_is_am) << endl;
	}

private:
	string begin_week_day;
	unsigned int begin_week_hours;
	bool begin_hours_is_am;

	string end_week_day;
	unsigned int end_week_hours;
	bool end_hours_is_am;

	unsigned int get_week_as_hours(bool from_end)
	{
		string week_days[7] = { "Sunday", "Monday", "Tuesday",
			"Wednesday", "Thursday", "Friday", "Saturday" };
		string week_day;
		if(from_end)
		{
			week_day = end_week_day;
		}
		else
		{
			week_day = begin_week_day;
		}
		unsigned int week_as_hours = 24;
		bool is_week_found = false;
		for(unsigned int i = 0; !is_week_found && i < 7; ++i)
		{
			if(week_day == week_days[i])
			{
				week_as_hours *= i;
				is_week_found = true;
			}
		}
		return week_as_hours;
	}

	unsigned int get_hours_format_24(bool from_end)
	{
		unsigned int hours;
		bool is_am;
		if(from_end)
		{
			hours = begin_week_hours;
			is_am = begin_hours_is_am;
		}
		else
		{
			hours = end_week_hours;
			is_am = end_hours_is_am;
		}
		return is_am ? hours : hours + 12;
	}

	string print_am_or_pm(bool is_am)
	{
		return is_am ? "AM" : "PM";
	}
};

void create_shifts(vector<student> &shifts);
void create_supervising_committee(vector<student> &shifts,
	vector<student> &committee);
void show_committee(vector<student> &committee);
bool intersects(student s1, student s2);

int main()
{
	vector<student> shifts;
	create_shifts(shifts);

	vector<student> committee;
	create_supervising_committee(shifts, committee);

	show_committee(committee);

	return 0;
}

void create_shifts(vector<student> &shifts)
{
	cout << "Inform each student shift" << endl;
	unsigned int id = 0;
	string begin_week_day;
	unsigned int begin_week_hours;
	string begin_am_or_pm;
	string end_week_day;
	unsigned int end_week_hours;
	string end_am_or_pm;
	while(cin >> begin_week_day
		>> begin_week_hours
		>> begin_am_or_pm
		>> end_week_day
		>> end_week_hours
		>> end_am_or_pm)
	{
		++id;
		bool begin_hours_is_am = false;
		if(begin_am_or_pm == "AM")
		{
			begin_hours_is_am = true;
		}
		bool end_hours_is_am = false;
		if(end_am_or_pm == "AM")
		{
			end_hours_is_am = true;
		}
		shifts.push_back(student(id, begin_week_day,
			begin_week_hours, begin_hours_is_am, end_week_day,
			end_week_hours, end_hours_is_am));
	}
}

void create_supervising_committee(vector<student> &shifts,
	vector<student> &committee)
{
	unsigned int marks = 0;
	while(marks != shifts.size())
	{
		student *earliest_end_time_student;
		unsigned int earliest_end_time = 169;
		for(student s : shifts)
		{
			if(!s.is_marked)
			{
				if(earliest_end_time > s.end_hours)
				{
					earliest_end_time_student = &s;
					earliest_end_time = s.end_hours;
				}
			}
		}
		student *latest_end_time_student;
		unsigned int latest_end_time = 0;
		for(student s : shifts)
		{
			if(intersects(*earliest_end_time_student, s))
			{
				if(latest_end_time < s.end_hours)
				{
					latest_end_time_student = &s;
					latest_end_time = s.end_hours;
				}
			}
		}
		for(student s : shifts)
		{
			if(intersects(*latest_end_time_student, s))
			{
				if(!s.is_marked)
				{
					++marks;
					s.is_marked = true;
				}
			}
		}
		if(!latest_end_time_student->is_marked)
		{
			shifts[latest_end_time_student->id-1].is_marked = true;
			++marks;
			committee.push_back(*latest_end_time_student);
		}
	}
}

void show_committee(vector<student> &committee)
{
	for(student s : committee)
	{
		s.print_shift();
	}
}

bool intersects(student s1, student s2)
{
	return (s1.begin_hours >= s2.begin_hours &&
		s1.begin_hours <= s2.end_hours) ||
		(s1.end_hours <= s2.end_hours &&
		s1.end_hours >= s2.begin_hours);
}
