require "spec_helper"

describe "recursive reverse" do
  def run(string)
    compile_and_run_with_args("chapter-4", "recursive_reverse", string).strip
  end

  it "reverses strings of odd length" do
    expect(run("one")).to eq("eno")
  end

  it "reverses strings of even length" do
    expect(run("four")).to eq("ruof")
  end
end
