describe "detab" do
  before :all do
    source = File.expand_path("../../detab.c", __FILE__)
    `cc -o detab #{source}`
  end

  def run(input)
    `echo "#{input}" | ./detab`
  end

  it "does nothing if there are no tabs" do
    expect(run("one two three")).to eq("one two three\n")
  end

  it "replaces tabs with the correct number of spaces" do
    expect(run("one\ttwo\tthree\tfour")).to eq("one     two     three   four\n")
  end
end
