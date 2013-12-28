require "spec_helper"

describe "stack operations" do
  def run(input)
    compile_and_run("chapter-4", "rpn_calc", input).strip
  end

  it "duplicates the top stack element when given command 'duplicate'" do
    expect(run("8 duplicate *").to_f).to eq(64)
  end

  it "swaps the top two stack elements when given the command 'swap'" do
    expect(run("1 2 swap -").to_f).to eq(1)
  end

  it "clears the stack when given the command 'clear'" do
    expect(run("1 2 clear")).to eq("error: stack empty\n\t0")
  end
end
