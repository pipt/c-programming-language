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
end
