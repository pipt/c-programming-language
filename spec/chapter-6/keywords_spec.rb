require "spec_helper"

describe "keywords" do
  def run(input)
    compile_and_run("chapter-6", "keywords", input).strip
  end

  it "counts keywords" do
    expect(
      run("if if float for float hello return")
    ).to eq("2 float\n   1 for\n   2 if\n   1 return")
  end

  it "counts underscores as part of a word" do
    expect(run("if if_for")).to eq("1 if")
  end

  it "doesn't count keywords in string constants" do
    expect(run('if \"for if for\"')).to eq("1 if")
  end
end
