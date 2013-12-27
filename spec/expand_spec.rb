require_relative "spec_helper"

describe "expand" do
  def run(input)
    compile_and_run_with_args("chapter-2", "expand", input).strip
  end

  it "handles a leading -" do
    expect(run("-a-c")).to eq("-abc")
  end

  it "handles a trailing -" do
    expect(run("a-c-")).to eq("abc-")
  end

  it "handles runs of ranges" do
    expect(run("a-c-e")).to eq("abcde")
  end

  it "handles ranges with nothing in them" do
    expect(run("a-b")).to eq("ab")
  end

  it "handles lower case letter ranges" do
    expect(run("a-z")).to eq(("a".."z").to_a.join)
  end

  it "handles upper case letter ranges" do
    expect(run("A-Z")).to eq(("A".."Z").to_a.join)
  end

  it "handles numeric ranges" do
    expect(run("0-9")).to eq("0123456789")
  end

  it "handles reverse ranges" do
    expect(run("e-a")).to eq("edcba")
  end

  it "handles multiple ranges" do
    expect(run("a-eA-E")).to eq("abcdeABCDE")
  end
end
