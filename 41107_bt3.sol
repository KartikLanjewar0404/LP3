// SPDX-License-Identifier: GPL-3.0

pragma solidity >=0.7.0 <0.9.0;



import "hardhat/console.sol";

contract College {

    struct Student {
        uint256 ID;
        string firstName;
        string lastName;
        uint256 marks;
    }

    address owner;
    
    uint256 public studCount = 0;

    mapping(uint256 => Student) public Students;

    modifier onlyOwner() {
        require(owner == msg.sender);
        _;
    }

    constructor() {
        owner = msg.sender;
    }

    function addStudent(string memory _firstName, string memory _lastName, uint256 _marks) public onlyOwner {

        studCount = studCount + 1;

        Students[studCount] = Student(studCount, _firstName, _lastName, _marks);
    }
    
    function getStudent(uint256 _id) public view returns(Student memory)
    {
        require(Students[_id].ID>0 && Students[_id].ID<=studCount,"Student Not Found");
        return Students[_id];
    }

    fallback() external {
        console.log("Fallback function called");
    }
}