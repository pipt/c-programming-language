require_relative "spec_helper"

describe "rightrot" do
  def run(x, n)
    compile_and_run_with_args("chapter-2", "rightrot", x.to_i(2), n).strip
  end

  let(:x) { "10100100010000100000100000010001" }

  it "rotates by 8 bits" do
    expect(run(x, 8)).to eq(x.chars.rotate(-8).join)
  end

  it "rotates by 16 bits" do
    expect(run(x, 16)).to eq(x.chars.rotate(-16).join)
  end

  it "rotates by 24 bits" do
    expect(run(x, 24)).to eq(x.chars.rotate(-24).join)
  end
end
