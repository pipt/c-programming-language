require "spec_helper"

describe "strncmp" do
  def run(input)
    compile_and_run("chapter-5", "sort", input).strip
  end

  let(:lines) { [
    "one",
    "two",
    "three",
    "four",
    "five"
  ] }

  it "sorts the input" do
    expect(run(lines.join("\n"))).to eq(lines.sort.join("\n"))
  end
end
