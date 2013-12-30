require "spec_helper"

def random_date
  Date.new(0, 1, 1) + rand(1_000_000)
end

describe "year and day to month and day" do
  def run(year, day)
    compile_and_run_with_args("chapter-5", "year_day", year, day).strip
  end

  it "works for several random dates" do
    10.times do
      date = random_date
      expect(run(date.year, date.yday)).to eq("#{date.mon} #{date.day}")
    end
  end

  it "reports an error if the year is negative" do
    expect(run(-1, 1)).to eq("error: year can't be negative")
  end

  it "reports and error if the year day is negative" do
    expect(run(1, -1)).to eq("error: year day can't be negative")
  end

  it "reports an error if the year is not a leap year and the year day > 365" do
    expect(run(2001, 366)).to eq("error: year day too big")
  end

  it "reports an error if the year is a leap year and the year day > 366" do
    expect(run(2004, 367)).to eq("error: year day too big")
  end

  it "returns the correct month and day if a leap year and day 366" do
    expect(run(2004, 366)).to eq("12 31")
  end
end

describe "year, month and day to year day" do
  def run(year, month, day)
    compile_and_run_with_args("chapter-5", "year_day", year, month, day).strip
  end

  it "works for several random dates" do
    10.times do
      date = random_date
      expect(run(date.year, date.mon, date.day)).to eq(date.yday.to_s)
    end
  end

  it "reports an error if the year is negative" do
    expect(run(-1, 1, 1)).to eq("error: year can't be negative")
  end

  it "reports an error if the month is negative" do
    expect(run(1, -1, 1)).to eq("error: month can't be negative or zero")
  end

  it "reports an error if the day is negative" do
    expect(run(1, 1, -1)).to eq("error: day can't be negative or zero")
  end

  it "reports an error if the month is > 12" do
    expect(run(1, 14, 1)).to eq("error: month can't be greater than 12")
  end

  it "reports an error if the month has 28 days in and the day > 28" do
    expect(run(2001, 2, 29)).to eq("error: day of month too big")
  end

  it "reports an error if the month has 29 days in and the day > 29" do
    expect(run(2004, 2, 30)).to eq("error: day of month too big")
  end

  it "reports an error if the month has 30 days in and the day > 30" do
    expect(run(2001, 4, 31)).to eq("error: day of month too big")
  end

  it "reports an error if the month has 31 days in and the day > 31" do
    expect(run(2004, 12, 32)).to eq("error: day of month too big")
  end
end
