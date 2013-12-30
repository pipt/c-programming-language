require "spec_helper"

describe "strcat" do
  def run(*args)
    compile_and_run_with_args("chapter-5", "strcat", args).strip
  end

  it "concatenates strings" do
    expect(run("hello", "world")).to eq("helloworld")
  end
end
