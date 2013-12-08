require_relative "spec_helper"

describe "detab" do
  def run(input)
    compile_and_run("chapter-1", "detab", input)
  end

  it "does nothing if there are no tabs" do
    expect(run("one two three")).to eq("one two three\n")
  end

  it "replaces tabs with the correct number of spaces" do
    expect(run("one\ttwo\tthree\tfour")).to eq("one     two     three   four\n")
  end
end
