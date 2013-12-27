require "spec_helper"

describe "lower" do
  def run(char)
    compile_and_run_with_args("chapter-2", "lower", char).strip
  end

  it "lowercases uppercase letters" do
    expect(run("X")).to eq("x")
  end

  it "leaves lowercase letters alone" do
    expect(run("x")).to eq("x")
  end

  it "leaves numbers alone" do
    expect(run("1")).to eq("1")
  end
end
