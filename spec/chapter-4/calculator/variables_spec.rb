require "spec_helper"

describe "variables" do
  it "sets and gets variables" do
    expect(calc("8 setx 9 sety getx gety +")).to eq(17)
  end

  it "has a variable for last printed value" do
    expect(calc_raw("8 9 +\nlast last +")).to eq("17\n\t34")
  end
end
