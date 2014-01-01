require "spec_helper"

describe "upper" do
  def program_name(_)
    "upper"
  end

  def run(input)
    compile_and_run("chapter-7", "upper_lower", input).strip
  end

  it "upper cases input" do
    expect(run("one")).to eq ("ONE")
  end
end

describe "lower" do
  def program_name(_)
    "lower"
  end

  def run(input)
    compile_and_run("chapter-7", "upper_lower", input).strip
  end

  it "lower cases input" do
    expect(run("ONE")).to eq ("one")
  end
end
