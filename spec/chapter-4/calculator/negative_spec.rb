require "spec_helper"

describe "negative numbers" do
  it "accepts negative numbers" do
    expect(calc("-12 -15 -")).to eq(3)
  end
end
