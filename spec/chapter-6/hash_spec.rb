require "spec_helper"

describe "hash" do
  def run
    compile_and_run("chapter-6", "hash").strip
  end

  it "works" do
    expect(run).to eq("2: Two\n3: three")
  end
end
