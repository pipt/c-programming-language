require "spec_helper"

describe "modulus" do
  it "calculates the modulus" do
    expect(calc("12 5 %")).to eq(2)
  end
end
