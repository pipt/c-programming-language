require "spec_helper"

describe "stack operations" do
  it "duplicates the top stack element when given command 'duplicate'" do
    expect(calc("8 duplicate *")).to eq(64)
  end

  it "swaps the top two stack elements when given the command 'swap'" do
    expect(calc("1 2 swap -")).to eq(1)
  end

  it "clears the stack when given the command 'clear'" do
    expect(calc_raw("1 2 clear")).to eq("error: stack empty\n\t0")
  end
end
