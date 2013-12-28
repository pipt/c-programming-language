require "spec_helper"

describe "variables" do
  def run(input)
    compile_and_run("chapter-4", "rpn_calc", input).strip
  end

  it "sets and gets variables" do
    expect(run("8 setx 9 sety getx gety +").to_f).to eq(17)
  end

  it "has a variable for last printed value" do
    expect(run("8 9 +\nlast last +")).to eq("17\n\t34")
  end
end
