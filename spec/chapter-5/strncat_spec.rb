require "spec_helper"

describe "strncat" do
  def run(*args)
    compile_and_run_with_args("chapter-5", "strncat", args).strip
  end

  it "concatenates strings, up to a limit" do
    expect(run(3, "hello", "world", "!")).to eq("helwor!")
  end
end
