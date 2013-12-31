require "spec_helper"

describe "strncmp" do
  def run(input)
    compile_and_run_with_stdin_and_args("chapter-5", "sort", input, args).strip
  end

  let(:lines) { [
    "one",
    "two",
    "three",
    "four",
    "five"
  ] }
  let(:args) { "" }

  context "sorting alphabetically" do
    it "sorts the input" do
      expect(run(lines.join("\n"))).to eq(lines.sort.join("\n"))
    end

    it "sorts numbers" do
      expect(run("1\n-3\n-1")).to eq("-1\n-3\n1")
    end

    it "sorts case-sensitively" do
      expect(run("a\nb\nA\nB")).to eq("A\nB\na\nb")
    end
  end

  context "sorting numerically" do
    let(:args) { "-n" }

    it "sorts numbers" do
      expect(run("1\n-3\n-1")).to eq("-3\n-1\n1")
    end
  end

  context "case-insensitive sort" do
    let(:args) { "-f" }

    it "sorts the input" do
      expect(run("a\nb\nA\nB")).to eq("A\na\nb\nB")
    end
  end

  context "sorting in reverse" do
    let(:args) { "-r" }

    it "sorts the input" do
      expect(run(lines.join("\n"))).to eq(lines.sort.reverse.join("\n"))
    end

    context "sorting numerically" do
      let(:args) { "-rn" }

      it "sorts numbers" do
        expect(run("1\n-3\n-1")).to eq("1\n-1\n-3")
      end
    end

    context "case-insensitive sort" do
      let(:args) { "-rf" }

      it "sorts the input" do
        expect(run("a\nB\nb\nA")).to eq("B\nb\na\nA")
      end
    end
  end
end
